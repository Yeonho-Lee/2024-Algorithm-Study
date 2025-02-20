package yeonho.Week_21;

import java.io.*;
import java.util.*;

public class P30805 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 수열 A 입력
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        // 수열 B 입력
        int M = Integer.parseInt(br.readLine());
        int[] B = new int[M + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= M; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        // LCS 테이블 생성
        int[][] dp = new int[N + 1][M + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // LCS 길이 출력
        int lcsLength = dp[N][M];
        System.out.println(lcsLength);

        if (lcsLength == 0)
            return;

        // LCS 역추적 (사전순으로 가장 나중인 수열 찾기)
        List<Integer> lcs = new ArrayList<>();
        int i = N, j = M;

        while (i > 0 && j > 0) {
            if (A[i] == B[j]) {
                lcs.add(A[i]); // 공통 원소 저장
                i--;
                j--; // 대각선 방향 이동
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                i--; // 위쪽으로 이동
            } else {
                j--; // 왼쪽으로 이동
            }
        }

        // 사전순 가장 나중인 결과는 뒤집혀 있으므로 반대로 출력
        Collections.reverse(lcs);
        for (int num : lcs) {
            System.out.print(num + " ");
        }
    }
}
