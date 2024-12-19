package yeonho.Week_12;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P11054_longestBitonic {
    static int N;
    static int[] A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        int bitonicLength = longestBitonicLength();
        System.out.println(bitonicLength);
    }

    private static int longestBitonicLength() {

        int[] LIS = new int[N]; // longest Increasing Subsequence
        int[] LDS = new int[N]; // longest Decreasing Subsequence

        // 1. Calculate LIS
        for (int i = 0; i < N; i++) {
            LIS[i] = 1;
            for (int j = 0; j < i; j++) {
                if (A[j] < A[i]) {
                    LIS[i] = Math.max(LIS[i], LIS[j] + 1);
                }
            }
        }
        // example
        // 1 5 2 1 4 3 4 5 2 1
        // LIS[0] = 1
        // LIS[1] = 2
        // LIS[2] = 2
        // LIS[3] = 1
        // LIS[4] = 2 -> 3

        // 2. Calculate LDS
        for (int i = N - 1; i >= 0; i--) {
            LDS[i] = 1;
            for (int j = N - 1; j > i; j--) {
                if (A[j] < A[i]) {
                    LDS[i] = Math.max(LDS[i], LDS[j] + 1);
                }
            }
        }

        // 3. Find the longest Bitonic Subsequence
        int maxBitonicLength = 0;
        for (int i = 0; i < N; i++) {
            maxBitonicLength = Math.max(maxBitonicLength, LIS[i] + LDS[i] - 1);
        }

        return maxBitonicLength;
    }

}
