package yeonho.Week_10;

import java.util.Scanner;

public class P2011_passwordCode_answer {
    static int[] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        if (s.charAt(0) == '0') {
            // 암호는 0으로 시작할 수 없으므로 경우의 수는 0
            System.out.println(0);
            return;
        }

        int size = s.length();
        dp = new int[size + 1];
        dp[0] = 1; // 초기값 설정
        dp[1] = 1; // 첫 글자가 유효하므로 경우의 수는 1

        for (int i = 2; i <= size; i++) {
            int oneDigit = s.charAt(i - 1) - '0'; // 한 자리 수
            int twoDigit = Integer.parseInt(s.substring(i - 2, i)); // 두 자리 수

            // 한 자리 수가 유효한 경우
            if (oneDigit >= 1) {
                dp[i] += dp[i - 1];
            }

            // 두 자리 수가 유효한 경우
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }

            // 1020 -> 102 / 0, 10 / 20
            // 1102 -> 110 / 2, 11 / 02

            dp[i] %= 1000000; // 문제 조건에 따라 모듈러 연산 적용
        }

        System.out.println(dp[size]);
        sc.close();
    }
}
