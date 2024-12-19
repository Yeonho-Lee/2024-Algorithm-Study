package yeonho.Week_13;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P20922_noOverlapping {
    static int N, K;
    static int[] A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        A = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int[] freq = new int[100001];
        int start = 0;
        int maxLength = 0;

        for (int end = 0; end < N; end++) {
            freq[A[end]]++;

            while (freq[A[end]] > K) {
                freq[A[start]]--;
                start++;
            }

            maxLength = Math.max(maxLength, end - start + 1);
        }
        System.out.println(maxLength);
    }
}
