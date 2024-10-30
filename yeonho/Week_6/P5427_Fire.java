package yeonho.Week_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P5427_Fire {
    static int T;
    static int W, H;
    static char[][] building;
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int[][] fireTime;
    static int[][] personTime;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            building = new char[H][W];
            personTime = new int[H][W];
            fireTime = new int[H][W];

            // 각 테스트 케이스마다 새로운 큐 생성
            Queue<int[]> fireQueue = new LinkedList<>();
            Queue<int[]> personQueue = new LinkedList<>();

            for (int i = 0; i < H; i++) {
                String line = br.readLine();
                for (int j = 0; j < W; j++) {
                    building[i][j] = line.charAt(j);
                    if (building[i][j] == '*') {
                        fireQueue.offer(new int[] { i, j });
                        fireTime[i][j] = 0; // 불의 시작 시간
                    } else if (building[i][j] == '@') {
                        personQueue.offer(new int[] { i, j });
                        personTime[i][j] = 0; // 상근이의 시작 시간
                    } else {
                        fireTime[i][j] = -1;
                        personTime[i][j] = -1;
                    }
                }
            }

            int result = bfs(fireQueue, personQueue);
            System.out.println(result == -1 ? "IMPOSSIBLE" : result);
        }
    }

    static int bfs(Queue<int[]> fireQueue, Queue<int[]> personQueue) {
        // 불의 확산
        while (!fireQueue.isEmpty()) {
            int[] fire = fireQueue.poll();
            int y = fire[0];
            int x = fire[1];

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (0 <= ny && ny < H && 0 <= nx && nx < W && building[ny][nx] == '.' && fireTime[ny][nx] == -1) {
                    fireTime[ny][nx] = fireTime[y][x] + 1;
                    fireQueue.offer(new int[] { ny, nx });
                }
            }
        }

        // 상근이의 이동
        while (!personQueue.isEmpty()) {
            int[] person = personQueue.poll();
            int y = person[0];
            int x = person[1];

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                // 경계 밖으로 나간 경우 탈출 성공
                if (nx < 0 || ny < 0 || nx >= W || ny >= H) {
                    return personTime[y][x] + 1;
                }

                if (building[ny][nx] == '.' && personTime[ny][nx] == -1
                        && (fireTime[ny][nx] == -1 || personTime[y][x] + 1 < fireTime[ny][nx])) {
                    personTime[ny][nx] = personTime[y][x] + 1;
                    personQueue.offer(new int[] { ny, nx });
                }
            }
        }

        return -1; // 탈출 불가
    }
}
