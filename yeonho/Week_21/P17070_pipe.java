package yeonho.Week_21;

import java.io.*;
import java.util.StringTokenizer;

public class P17070_pipe {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] grid = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // DP 테이블 (가로: 0, 세로: 1, 대각선: 2)
        int[][][] dp = new int[N][N][3];

        // 초기 상태: (0,1) 위치에 가로 방향으로 파이프가 존재
        dp[0][1][0] = 1;

        for (int r = 0; r < N; r++) {
            for (int c = 1; c < N; c++) {
                if (grid[r][c] == 1)
                    continue; // 벽이 있는 경우 이동 불가능

                // 가로 방향 갱신
                dp[r][c][0] += dp[r][c - 1][0] + dp[r][c - 1][2];

                // 세로 방향 갱신
                if (r > 0) {
                    dp[r][c][1] += dp[r - 1][c][1] + dp[r - 1][c][2];
                }

                // 대각선 방향 갱신 (3칸 모두가 빈칸이어야 가능)
                if (r > 0 && grid[r - 1][c] == 0 && grid[r][c - 1] == 0) {
                    dp[r][c][2] += dp[r - 1][c - 1][0] + dp[r - 1][c - 1][1] + dp[r - 1][c - 1][2];
                }
            }
        }

        // 정답 출력: (N-1, N-1)에 도착할 수 있는 모든 경우의 수 합
        int answer = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
        System.out.println(answer);
    }
}
