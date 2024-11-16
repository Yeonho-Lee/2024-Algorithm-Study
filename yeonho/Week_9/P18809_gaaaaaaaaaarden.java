package yeonho.Week_9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class P18809_gaaaaaaaaaarden {
    static int N, M;
    static int G, R;
    static Ground[][] map;
    static List<Point> plantableCells = new ArrayList<>();
    static int maxFlowers;

    static class Point {
        int r, c;

        public Point(int r, int c) {
            this.r = r;
            this.c = c;
        }

        @Override
        public String toString() {
            return "Point [r=" + r + ", c=" + c + "]";
        }
    }

    enum Ground {
        LAKE, PLAIN, CAN_PLANT;

        public static Ground setGround(int i) {
            if (i == 0) {
                return LAKE;
            } else if (i == 1) {
                return PLAIN;
            } else // (i == 2)
            {
                return CAN_PLANT;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        G = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        map = new Ground[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Ground.setGround(Integer.parseInt(st.nextToken()));
                if (map[i][j] == Ground.CAN_PLANT) {
                    plantableCells.add(new Point(i, j));
                }
            }
        }
        dfs(0, 0, 0, new ArrayList<>(), new ArrayList<>());
        System.out.println(maxFlowers);
    }

    // 배양액의 시작점을 고르는 경우의 수를 백트래킹으로 탐색
    static void dfs(int index, int greenCount, int redCount, List<Point> greenPositions, List<Point> redPositions) {
        // 초록 배양액과 빨간 배양액을 모두 선택한 경우
        if (greenCount == G && redCount == R) {
            // System.out.println("run bfs -> green: " + greenPositions.toString() + " red:
            // " + redPositions.toString());
            maxFlowers = Math.max(maxFlowers, bfs(greenPositions, redPositions));
            return;
        }

        if (index == plantableCells.size()) {
            return;
        }

        // 배양액을 놓을 수 있는 위치 가져오기
        Point current = plantableCells.get(index);

        // 초록 배양액을 놓는 경우
        if (greenCount < G) {
            greenPositions.add(current);
            dfs(index + 1, greenCount + 1, redCount, greenPositions, redPositions);
            greenPositions.remove(greenPositions.size() - 1);
        }
        // 빨강 배양액을 놓는 경우
        if (redCount < R) {
            redPositions.add(current);
            dfs(index + 1, greenCount, redCount + 1, greenPositions, redPositions);
            redPositions.remove(redPositions.size() - 1);
        }
        // 배양액을 이 위치에 놓지 않는 경우
        dfs(index + 1, greenCount, redCount, greenPositions, redPositions);
    }

    // 각 경우의 수마다 피울 수 있는 꽃의 경우의 수 계산
    static int bfs(List<Point> greens, List<Point> reds) {
        Queue<Point> greenQueue = new LinkedList<>();
        Queue<Point> redQueue = new LinkedList<>();
        int[][] greenTime = new int[N][M];
        int[][] redTime = new int[N][M];
        boolean[][] flowered = new boolean[N][M];
        int[] dx = { -1, 1, 0, 0 };
        int[] dy = { 0, 0, -1, 1 };
        int flowers = 0;

        // 초기화
        for (int[] row : greenTime)
            Arrays.fill(row, -1);
        for (int[] row : redTime)
            Arrays.fill(row, -1);

        for (Point g : greens) {
            greenQueue.add(g);
            greenTime[g.r][g.c] = 0;
        }
        for (Point r : reds) {
            redQueue.add(r);
            redTime[r.r][r.c] = 0;
        }

        // queue 돌면서 핀 꽃의 개수 계산
        while (!greenQueue.isEmpty() && !redQueue.isEmpty()) {
            // System.out.println("Queue: " + greenQueue.toString() + " / " +
            // redQueue.toString());
            // 초록 배양액 확산
            int greenSize = greenQueue.size();
            // System.out.println(greenSize);
            for (int i = 0; i < greenSize; i++) {
                Point p = greenQueue.poll();
                // System.out.println(p.toString());
                if (flowered[p.r][p.c])
                    continue;
                for (int d = 0; d < 4; d++) {
                    int nr = p.r + dx[d];
                    int nc = p.c + dy[d];
                    if (isInBounds(nr, nc)
                            && map[nr][nc] != Ground.LAKE
                            && greenTime[nr][nc] == -1 && redTime[nr][nc] == -1) {
                        greenTime[nr][nc] = greenTime[p.r][p.c] + 1;
                        greenQueue.add(new Point(nr, nc));
                    }
                }
            }

            // 빨간 배양액 확산
            int redSize = redQueue.size();
            // System.out.println(redSize);
            for (int i = 0; i < redSize; i++) {
                Point p = redQueue.poll();
                // System.out.println(p.toString());
                if (flowered[p.r][p.c])
                    continue; // 이미 꽃이 피었다면 건너뜀
                for (int d = 0; d < 4; d++) {
                    int nr = p.r + dx[d];
                    int nc = p.c + dy[d];
                    if (isInBounds(nr, nc)
                            && map[nr][nc] != Ground.LAKE) {
                        if (redTime[nr][nc] == -1 && greenTime[nr][nc] == -1) {
                            redTime[nr][nc] = redTime[p.r][p.c] + 1;
                            redQueue.add(new Point(nr, nc));
                        } else if (redTime[p.r][p.c] != -1 && !flowered[nr][nc]
                                && greenTime[nr][nc] == redTime[p.r][p.c] + 1) {
                            flowers++;
                            flowered[nr][nc] = true;
                        }
                    }
                }
            }
        }
        return flowers;
    }

    // 범위 검사 메서드
    static boolean isInBounds(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}
