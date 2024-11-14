package yeonho.Week_8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P16933_breakingWall3 {

    enum Time {
        DAY, NIGHT;

        public Time toggle() {
            return this == DAY ? NIGHT : DAY;
        }
    }

    static class Position {
        int row, col, distance, broken;
        Time timeOfDay;

        public Position(int row, int col, int distance, Time timeOfDay, int broken) {
            this.row = row;
            this.col = col;
            this.distance = distance;
            this.timeOfDay = timeOfDay;
            this.broken = broken;
        }

        @Override
        public String toString() {
            return "Position [row=" + row + ", col=" + col + ", distance=" + distance + ", timeOfDay=" + timeOfDay
                    + ", broken=" + broken + "]";
        }
    }

    static int N, M, K;
    static int[][] map;
    static boolean[][][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        // N : rows, M: columns, K:
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        visited = new boolean[N][M][K + 1];
        for (int r = 0; r < N; r++) {
            String line = br.readLine();
            for (int c = 0; c < M; c++) {
                map[r][c] = line.charAt(c) - '0';
            }
        }

        System.out.println(bfs());
    }

    static int bfs() {
        Queue<Position> queue = new LinkedList<>();
        queue.offer(new Position(0, 0, 1, Time.DAY, 0));
        int[] dr = { 0, 0, -1, 1 };
        int[] dc = { 1, -1, 0, 0 };

        while (!queue.isEmpty()) {
            Position current = queue.poll();

            if (current.row == N - 1 && current.col == M - 1) {
                return current.distance;
            }

            for (int i = 0; i < 4; i++) {
                int nr = current.row + dr[i];
                int nc = current.col + dc[i];

                if (0 <= nr && nr < N && 0 <= nc && nc < M && current.broken <= K) {
                    // if map[nr][nc] == 0, not visited
                    if (map[nr][nc] == 0 && !visited[nr][nc][current.broken]) {
                        visited[nr][nc][current.broken] = true;
                        queue.offer(
                                new Position(nr, nc, current.distance + 1, current.timeOfDay.toggle(), current.broken));
                    }
                    // if map[nr][nc] == 1, not visited
                    if (map[nr][nc] == 1 && current.broken < K && !visited[nr][nc][current.broken + 1]) {
                        if (current.timeOfDay == Time.DAY) {
                            visited[nr][nc][current.broken + 1] = true;
                            queue.offer(new Position(nr, nc, current.distance + 1, current.timeOfDay.toggle(),
                                    current.broken + 1));
                        } else {
                            // current.timeOfDay == Time.NIGHT -> 부수지 못하니까 dist만 늘려서 offer
                            queue.offer(new Position(current.row, current.col, current.distance + 1,
                                    current.timeOfDay.toggle(), current.broken));
                        }
                    }
                }
            }
        }
        return -1;
    }
}
