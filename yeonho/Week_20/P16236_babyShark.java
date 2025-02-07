package yeonho.Week_20;

import java.io.*;
import java.util.*;

public class P16236_babyShark {
    static int N;
    static int[][] space;
    static int x, y, size = 2, eatCount = 0;
    static int time = 0;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    // 물고기 객체 (비교 가능: 거리 -> 행 -> 열 순으로 정렬)
    static class Fish implements Comparable<Fish> {
        int x, y, dist;

        public Fish(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }

        @Override
        public int compareTo(Fish o) {
            if (this.dist == o.dist) {
                if (this.x == o.x)
                    return this.y - o.y;
                return this.x - o.x;
            }
            return this.dist - o.dist;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        space = new int[N][N];

        // 공간 초기화 및 아기 상어 위치 찾기
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                space[i][j] = Integer.parseInt(st.nextToken());
                if (space[i][j] == 9) {
                    y = i;
                    x = j;
                    space[i][j] = 0; // 아기 상어 위치는 빈칸으로 변경
                }
            }
        }

        // 아기 상어가 먹을 수 있는 물고기가 없을 때까지 반복
        while (true) {
            Fish target = bfs(); // 가장 가까운 먹을 수 있는 물고기 찾기
            if (target == null)
                break;

            // 물고기를 먹고 이동
            space[target.x][target.y] = 0;
            x = target.y;
            y = target.x;
            time += target.dist;
            eatCount++;

            // 아기 상어 크기 증가
            if (eatCount == size) {
                size++;
                eatCount = 0;
            }
        }
        System.out.println(time); // 총 시간 출력
    }

    // BFS 탐색을 통해 가장 가까운 먹을 수 있는 물고기 찾기
    static Fish bfs() {
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[N][N];
        queue.offer(new int[] { y, x, 0 });
        visited[y][x] = true;
        List<Fish> fishList = new ArrayList<>();

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int cx = cur[1], cy = cur[0], dist = cur[2];

            // 상하좌우 탐색
            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                // 유효한 좌표 & 방문하지 않음 & 아기 상어 크기 이하인 경우만 이동 가능
                if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[ny][nx] && space[ny][nx] <= size) {
                    visited[ny][nx] = true;
                    queue.offer(new int[] { ny, nx, dist + 1 });

                    // 먹을 수 있는 물고기라면 리스트에 추가
                    if (space[ny][nx] > 0 && space[ny][nx] < size) {
                        fishList.add(new Fish(ny, nx, dist + 1));
                    }
                }
            }
        }
        // 가장 가까운 물고기 반환 (없으면 null)
        return fishList.isEmpty() ? null : Collections.min(fishList);
    }
}
