package yeonho.Week_9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P20304_makingPassword_test {
    static int N; // 0 - 1_000_000
    static int M; // 1 - 100_000
    static int[] attemptedPasswords; // 0 - N

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        attemptedPasswords = new int[M];
        for (int i = 0; i < M; i++) {
            attemptedPasswords[i] = Integer.parseInt(st.nextToken());
        }

        int maxSafety = -1;
        int safestPassword = -1;

        for (int candidate = 0; candidate <= N; candidate++) {
            int minHammingDistance = Integer.MAX_VALUE;

            // 현재 후보 비밀번호와 시도된 비밀번호들 간의 최소 해밍거리 계산
            for (int attempted : attemptedPasswords) {
                int hammingDistance = Integer.bitCount(candidate ^ attempted);
                minHammingDistance = Math.min(minHammingDistance, hammingDistance);
            }

            // 최대 안전도 업데이트
            if (minHammingDistance > maxSafety) {
                maxSafety = minHammingDistance;
                safestPassword = candidate;
            }
        }

        System.out.println(maxSafety);
    }
}
