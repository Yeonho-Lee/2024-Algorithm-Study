package yeonho.Week_12;

import java.util.Scanner;

public class P9251_LCS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s1 = sc.nextLine().trim().toCharArray();
        char[] s2 = sc.nextLine().trim().toCharArray();

        int lcsLength = findLCS(s1, s2);
        System.out.println(lcsLength);
        sc.close();
    }

    private static int findLCS(char[] s1, char[] s2) {
        int[][] dp = new int[s1.length + 1][s2.length + 1];

        for (int i = 1; i <= s1.length; i++) {
            for (int j = 1; j <= s2.length; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[s1.length][s2.length];
    }
}
