package yeonho.Week_10;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P2482_colorCircle {
    static int N, K;
    static int[][] dp;
    static final int MOD = 1_000_000_003;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        if (K >= (N + 1) / 2) {
            System.out.println(0);
            return;
        }

        dp = new int[N + 1][K + 1];

        // 초기화
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1; // 색 안 고르는 경우 1
            dp[i][1] = i; // i 개 중 1개를 고르는 경우 i;
        }

        // DP 점화식 계산
        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= K; j++) {
                if (i >= j) { // 선택할 색의 수가 전체 색 수를 넘을 수 없음
                    dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
                }
            }
        }

    }
}
