package yeonho.Week_10;

import java.util.Scanner;

public class P2011_passwordCode {
    static int[] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        //
        // Sn 까지의 경우의 수
        // Sn = [Sn-1] -> Sn 은 무조건 말이 된
        // [Sn-2] -> Sn-1~Sn은 말이 되는지 따져봐야 됨
        //
        int size = s.length();
        dp = new int[size + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= size; i++) {
            dp[i] += dp[i - 1];
            if (Integer.parseInt(s.substring(i - 2, i)) <= 26) {
                dp[i] += dp[i - 2];
            }
            dp[i] %= 1000_000;
        }

        System.out.println(dp[size]);
    }
}
