package yeonho.Week_12;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P12865_normalBackpack2 {
    static int N, K;
    static int[] W, V;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        W = new int[N + 1];
        V = new int[N + 1];

        dp = new int[K + 1];
        // dp[i][k] -> i번째 물건까지 고려했을 때, 배낭의 허용 무게가 k일 때의 최대 가치

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            W[i] = Integer.parseInt(st.nextToken());
            V[i] = Integer.parseInt(st.nextToken());
        }

        knapsack();
        System.out.println(dp[K]);

    }

    static void knapsack() {
        for (int i = 1; i <= N; i++) {
            for (int k = K; k >= W[i]; k--) {
                dp[k] = Math.max(dp[k], V[i] + dp[k - W[i]]);
            }
        }
    }
}
