package yeonho.Week_12;

import java.util.Scanner;

public class P2225_sum {
    static int N, K;
    static final int MOD = 1_000_000_000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        int[][] dp = new int[K + 1][N + 1];

        // 초기 상태
        for (int i = 0; i <= K; i++) {
            dp[i][0] = 1; // 합이 0인 경우의 수
        }

        // DP 점화식 계산
        for (int k = 1; k <= K; k++) {
            for (int n = 1; n <= N; n++) {
                dp[k][n] = (dp[k - 1][n] + dp[k][n - 1]) % MOD;
            }
        }

        // 결과 출력
        System.out.println(dp[K][N]);

        sc.close();
    }
}
