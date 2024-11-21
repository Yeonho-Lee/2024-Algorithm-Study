package yeonho.Week_8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P16920_expandingGame {
    static int N, M, P;
    static int[] S;
    static char[][] Map;
    static int[] Castle;
    static int[] dr = { 0, 0, -1, 1 };
    static int[] dc = { -1, 1, 0, 0 };
    static boolean[][] built;
    static Queue<Point> queue = new LinkedList<>();

    static class Point {
        int r, c, player;

        public Point(int r, int c, int player) {
            this.r = r;
            this.c = c;
            this.player = player;
        }

        @Override
        public String toString() {
            return "Point [r=" + r + ", c=" + c + ", player=" + player + "]";
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        Map = new char[N][M];
        built = new boolean[N][M];
        S = new int[P + 1];
        Castle = new int[P + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= P; i++) {
            S[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                char c = line.charAt(j);
                Map[i][j] = c;
            }
        }

        bfs();
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= P; i++) {
            sb.append(Castle[i]).append(" ");
        }
        System.out.println(sb.toString());
    }

    static void bfs() {
        // 시작 전 queue 세팅 -> 1 ~ 9 순서대로 queue에 넣어줌

        for (int p = 1; p <= P; p++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    char c = Map[i][j];
                    int player = c - '0';
                    if (player == p) {
                        built[i][j] = true;
                        Castle[player]++;
                        queue.offer(new Point(i, j, player));
                    }
                }
            }
        }

        while (!queue.isEmpty()) {
            Point current = queue.poll();
            // System.out.println(current.toString());
            for (int i = 0; i < 4; i++) {
                for (int j = 1; j <= S[current.player]; j++) {
                    int nr = current.r + dr[i] * j;
                    int nc = current.c + dc[i] * j;

                    if (0 <= nr && nr < N && 0 <= nc && nc < M && !built[nr][nc] && Map[nr][nc] != '#') {
                        built[nr][nc] = true;
                        queue.offer(new Point(nr, nc, current.player));
                        Castle[current.player]++;
                    }
                }
            }

        }
    }
}
