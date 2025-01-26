package yeonho.Week_06;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P7576_Tomato {
    static int C, R;
    static int[][] tomatoes;
    static int[][] days;
    static Queue<int[]> queue = new LinkedList<>();
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        tomatoes = new int[R][C];
        days = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                tomatoes[i][j] = Integer.parseInt(st.nextToken());
                if (tomatoes[i][j] == 1) {
                    queue.add(new int[] { i, j });
                } else if (tomatoes[i][j] == 0) {
                    days[i][j] = -1;
                }
            }
        }
        System.out.println(bfs());
    }

    static int bfs() {
        while (!queue.isEmpty()) {
            int[] tomato = queue.poll();
            int r = tomato[0];
            int c = tomato[1];

            for (int i = 0; i < 4; i++) {
                int nc = c + dy[i];
                int nr = r + dx[i];

                if (0 <= nc && nc < C && 0 <= nr && nr < R && tomatoes[nr][nc] == 0) {
                    tomatoes[nr][nc] = 1;
                    days[nr][nc] = days[r][c] + 1;
                    queue.add(new int[] { nr, nc });
                }
            }
        }

        int maxDays = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (days[i][j] == -1) {
                    return -1;
                }
                maxDays = Math.max(maxDays, days[i][j]);
            }
        }

        return maxDays;
    }
}
