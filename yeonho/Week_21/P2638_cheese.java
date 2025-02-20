package yeonho.Week_21;

import java.io.*;
import java.util.*;

public class P2638_cheese {
    static int N, M;
    static int[][] cheese;
    static boolean[][] visited;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        cheese = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                cheese[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int time = 0;
        while (true) {
            visited = new boolean[N][M];
            if (!meltCheese())
                break;
            time++;
        }
        System.out.println(time);
    }

    static boolean meltCheese() {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] { 0, 0 });
        visited[0][0] = true;

        int[][] airContact = new int[N][M];
        boolean hasCheese = false;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny])
                    continue;

                if (cheese[nx][ny] == 1) {
                    airContact[nx][ny]++;
                    if (airContact[nx][ny] >= 2) {
                        cheese[nx][ny] = 0;
                        hasCheese = true;
                    }
                } else {
                    queue.add(new int[] { nx, ny });
                }
                visited[nx][ny] = true;
            }
        }
        return hasCheese;
    }
}
