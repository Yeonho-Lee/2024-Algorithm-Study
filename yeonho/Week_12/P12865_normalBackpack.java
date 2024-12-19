package yeonho.Week_12;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P12865_normalBackpack {
    static int N, K;
    static int[] W, V;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        W = new int[N + 1];
        V = new int[N + 1];

        dp = new int[N + 1][K + 1];
        // dp[i][k] -> i번째 물건까지 고려했을 때, 배낭의 허용 무게가 k일 때의 최대 가치

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            W[i] = Integer.parseInt(st.nextToken());
            V[i] = Integer.parseInt(st.nextToken());
        }

        knapsack();
        System.out.println(dp[N][K]);

    }

    static void knapsack() {
        for (int k = 1; k <= K; k++) {
            // 각 무게마다 최대 가치 갱신
            for (int i = 1; i <= N; i++) {
                if (k - W[i] < 0) {
                    // 만약 현재 아이템을 담을 수 없다면 이전 행의 값으로 dp를 갱신
                    dp[i][k] = dp[i - 1][k];
                } else {
                    // 현재 아이템을 담을 수 있다면 둘중의 max 값으로 갱신
                    dp[i][k] = Math.max(dp[i - 1][k], dp[i - 1][k - W[i]] + V[i]);
                }
            }
        }
    }
}
