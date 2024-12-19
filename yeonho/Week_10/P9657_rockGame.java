package yeonho.Week_10;

import java.util.Scanner;

public class P9657_rockGame {
    static int N;
    static boolean[] dp; // i개의 돌이 있을 때 승리하는 플레이어
                         // true - 상근, false = 창영

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        dp = new boolean[N + 1];
        // dp[i] = true 이려면
        // 상근이가 돌을 1개 3개 4개 가져가기 전 상대방의 턴에서 남은 돌 개수가 창영이의 승리 상태여야 함
        // 반대이면 창영이가 승리

        // 초기값 설정
        if (N >= 1)
            dp[1] = true; // 상근 승리
        if (N >= 2)
            dp[2] = false; // 창영 승리
        if (N >= 3)
            dp[3] = true; // 상근 승리
        if (N >= 4)
            dp[4] = true; // 상근 승리

        for (int i = 5; i <= N; i++) {
            if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) {
                dp[i] = true;
            } else {
                dp[i] = false;
            }
        }

        // 결과 출력
        System.out.println(dp[N] ? "SK" : "CY");
    }
}
