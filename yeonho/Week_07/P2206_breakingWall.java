package yeonho.Week_07;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P2206_breakingWall {
    static int N, M;
    static int[][] map;
    static boolean[][][] visited;

    static class Position {
        int x, y, dist, broken;

        public Position(int x, int y, int dist, int broken) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.broken = broken;
        }

        @Override
        public String toString() {
            return "Position [x=" + x + ", y=" + y + ", dist=" + dist + ", broken=" + broken + "]";
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        visited = new boolean[N][M][2];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }
        System.out.println(bfs());
    }

    static int bfs() {
        Queue<Position> queue = new LinkedList<>();
        queue.offer(new Position(0, 0, 1, 0)); // x, y, broken
        visited[0][0][0] = true;

        int[] dx = { -1, 1, 0, 0 };
        int[] dy = { 0, 0, -1, 1 };

        while (!queue.isEmpty()) {
            Position current = queue.poll();

            // if destination
            if (current.x == N - 1 && current.y == M - 1) {
                return current.dist;
            }

            // 연결된 곳을 순회
            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    // if a path (0) and not visited
                    if (map[nx][ny] == 0 && !visited[nx][ny][current.broken]) {
                        visited[nx][ny][current.broken] = true;
                        queue.offer(new Position(nx, ny, current.dist + 1, current.broken));
                    }
                    // if a wall (1) and not broken yet
                    else if (map[nx][ny] == 1 && current.broken == 0 && !visited[nx][ny][1]) {
                        visited[nx][ny][1] = true;
                        queue.offer(new Position(nx, ny, current.dist + 1, 1));
                    }
                }
            }
        }
        // queue over and didn't reach target
        return -1;
    }
}
