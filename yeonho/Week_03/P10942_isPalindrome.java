package yeonho.Week_03;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class P10942_isPalindrome {
    // N - 칠판에 적은 수 개수
    // M - 질문의 개수
    static int N, M;
    static int S, E; // start, end
    static int[] numbs; // 칠판에 적은 수
    static boolean[][] isPalindrome; // i 부터 j까지 palindrome?

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // N, numbs 받기
        N = Integer.parseInt(br.readLine());
        numbs = new int[N + 1];
        isPalindrome = new boolean[N + 1][N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            numbs[i] = Integer.parseInt(st.nextToken());
        }

        // dp 저장
        processPalindromeInfo();

        // M 받고, S, E 받으면서
        M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            if (isPalindrome[S][E]) {
                bw.write("1\n");
            } else {
                bw.write("0\n");
            }
        }

        bw.flush();
        bw.close();
        br.close();

    }

    static void processPalindromeInfo() {
        // size 1
        for (int i = 1; i <= N; i++) {
            isPalindrome[i][i] = true;
        }

        // size 2
        for (int i = 1; i <= N - 1; i++) {
            if (numbs[i] == numbs[i + 1]) {
                isPalindrome[i][i + 1] = true;
            }
        }

        // size 3 or more
        // dp[i][j] = left == right && dp[i+1][j-1]
        for (int size = 3; size <= N; size++) {
            for (int i = 1; i <= N - size + 1; i++) {
                int left = i;
                int right = i + size - 1;
                if (numbs[left] == numbs[right] && isPalindrome[left + 1][right - 1]) {
                    isPalindrome[left][right] = true;
                }
            }
        }
    }
}