
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P2294_Coin2 {
    // n - 동전의 종류
    // k - 원하는 동전의 합
    static int n, k;

    static int[] coins;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        // input
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        coins = new int[n];
        dp = new int[k + 1];
        for (int i = 0; i < n; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }

        initializeDP();
        calculateDP();
        int answer = (dp[k] == 10_000_000 ? -1 : dp[k]);
        System.out.println(answer);
    }

    static void initializeDP() {
        for (int i = 0; i <= k; i++) {
            dp[i] = 10_000_000;
        }
    }

    static void calculateDP() {
        dp[0] = 0;
        for (int price = 1; price <= k; price++) {
            for (int i = 0; i < n; i++) {
                if (price - coins[i] >= 0) {
                    dp[price] = Math.min(dp[price - coins[i]] + 1, dp[price]);
                }
            }
        }
    }
}
