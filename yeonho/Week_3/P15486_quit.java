
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P15486_quit {
    static int Days;
    static int[] Time, Price;
    static int[] dp;

    public static void main(String[] args) throws IOException {

        // process Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Days = Integer.parseInt(br.readLine());
        StringTokenizer st;
        Time = new int[Days + 1];
        Price = new int[Days + 1];
        dp = new int[Days + 1];
        for (int i = 0; i < Days; i++) {
            st = new StringTokenizer(br.readLine());
            Time[i + 1] = Integer.parseInt(st.nextToken());
            Price[i + 1] = Integer.parseInt(st.nextToken());
        }

        // dp
        // needed time? - i + time - 1 (당일 포함이기 때문)
        // dp[i] - i 일 상담을 끝내서 얻을 수 있는 최대 수익
        dp[0] = 0;
        for (int day = 1; day <= Days; day++) {
            // 전날 수익과 비교하여 최대 수익으로 갱신
            dp[day] = Math.max(dp[day], dp[day - 1]);

            // 상담을 오늘 시작할 수 있으면
            if (day + Time[day] - 1 <= Days) {
                dp[day + Time[day] - 1] = Math.max(dp[day + Time[day] - 1], dp[day - 1] + Price[day]);
            }

        }

        System.out.println(dp[Days]);

    }
}