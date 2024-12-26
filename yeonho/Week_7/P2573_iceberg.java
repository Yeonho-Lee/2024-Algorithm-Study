package yeonho.Week_7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P2573_iceberg {
    static int N, M; // col, row
    static int[][] map;
    static boolean[][] visited;
    static int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(simulateMelting());
    }

    static int simulateMelting() {
        int year = 0;

        while (true) {
            year++;
            int[][] meltingAmount = new int[N][M];

            // calculate melting - how many?
            for (int i = 1; i < N - 1; i++) {
                for (int j = 1; j < M - 1; j++) {
                    if (map[i][j] > 0) {
                        int adjacentWater = 0;
                        for (int[] dir : directions) {
                            int ni = i + dir[0];
                            int nj = j + dir[1];
                            // 바다가 옆에 있다면? -> ++
                            if (map[ni][nj] == 0) {
                                adjacentWater++;
                            }
                        }
                        meltingAmount[i][j] = adjacentWater;
                    }
                }
            }

            // update heights
            for (int i = 1; i < N - 1; i++) {
                for (int j = 1; j < M - 1; j++) {
                    if (map[i][j] > 0) {
                        map[i][j] = Math.max(0, map[i][j] - meltingAmount[i][j]);
                    }
                }
            }

            // check for components
            int components = countComponents();
            if (components > 1) {
                return year;
            }
            if (isAllMelted()) {
                return 0;
            }
        }
    }

    static int countComponents() {
        visited = new boolean[N][M];
        int components = 0;

        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (map[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j);
                    components++;
                }
            }
        }

        return components;
    }

    static void bfs(int startR, int startC) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] { startR, startC });
        visited[startR][startC] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            for (int[] dir : directions) {
                int nr = current[0] + dir[0];
                int nc = current[1] + dir[1];
                if (0 <= nr && nr < N && 0 <= nc && nc < M && !visited[nr][nc] && map[nr][nc] > 0) {
                    visited[nr][nc] = true;
                    queue.offer(new int[] { nr, nc });
                }
            }
        }
    }

    static boolean isAllMelted() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0) {
                    return false;
                }
            }
        }
        return true;
    }
}
