package yeonho.Week_09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P3197_swanLake {
    static int R, C; // 1<= R, C <= 1500
    static char[][] Map;
    static boolean[][] swanVisited;
    static Position[] swans = new Position[2];
    static Queue<Position> meltQueue = new LinkedList<>();
    static Queue<Position> swanQueue = new LinkedList<>();
    static Queue<Position> nextSwanQueue = new LinkedList<>();
    static int[] dr = { 0, 0, -1, 1 };
    static int[] dc = { -1, 1, 0, 0 };
    static int days = 0;

    static class Position {
        int r, c;

        public Position(int r, int c) {
            this.r = r;
            this.c = c;
        }

        @Override
        public String toString() {
            return "Position [r=" + r + ", c=" + c;
        }

    }

    public static void main(String[] args) throws IOException {
        // --------------
        // Process Input
        // --------------
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        Map = new char[R][C];
        swanVisited = new boolean[R][C];
        int idx = 0;
        for (int r = 0; r < R; r++) {
            String line = br.readLine();
            for (int c = 0; c < C; c++) {
                Map[r][c] = line.charAt(c);
                if (Map[r][c] == 'L') {
                    swans[idx] = new Position(r, c);
                    swanVisited[r][c] = true;
                    idx++;
                }
                if (Map[r][c] != 'X') {
                    meltQueue.offer(new Position(r, c));
                }
            }
        }
        swanQueue.offer(swans[0]);

        while (!swansCanMeet()) {
            days++;
            melt();
        }
        System.out.println(days);
    }

    static boolean swansCanMeet() {
        Queue<Position> nextQueue = new LinkedList<>();
        while (!swanQueue.isEmpty()) {
            Position swan = swanQueue.poll();

            for (int i = 0; i < 4; i++) {
                int nr = swan.r + dr[i];
                int nc = swan.c + dc[i];

                if (!isInRange(nr, nc)) {
                    continue;
                }
                if (nr == swans[1].r && nc == swans[1].c) {
                    // 다른 백조가 있는 곳에 도착
                    return true;
                } else if (!swanVisited[nr][nc]) {
                    // 방문하지 않은 곳이라면
                    swanVisited[nr][nc] = true;
                    if (Map[nr][nc] == '.') {
                        swanQueue.offer(new Position(nr, nc));
                    } else {
                        nextQueue.offer(new Position(nr, nc));
                    }
                }

            }
        }
        swanQueue = nextQueue;
        return false;
    }

    static boolean isInRange(int nr, int nc) {
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
            return false;
        }
        return true;
    }

    static void melt() {
        Queue<Position> nextQueue = new LinkedList<>();
        while (!meltQueue.isEmpty()) {
            Position current = meltQueue.poll();
            for (int i = 0; i < 4; i++) {
                int nr = current.r + dr[i];
                int nc = current.c + dc[i];

                if (!isInRange(nr, nc))
                    continue;
                if (Map[nr][nc] == 'X') {
                    Map[nr][nc] = '.';
                    nextQueue.offer(new Position(nr, nc));
                }
            }
        }
        meltQueue = nextQueue;
    }
}
