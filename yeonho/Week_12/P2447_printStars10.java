package yeonho.Week_12;

import java.util.Scanner;

public class P2447_printStars10 {
    static int N;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        char[][] pattern = printStars(N);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(pattern[i]);
            sb.append("\n");
        }
        System.out.print(sb);
        sc.close();
    }

    static char[][] printStars(int n) {
        char[][] arr = new char[n][n];

        fillPattern(arr, n, 0, 0);
        return arr;
    }

    private static void fillPattern(char[][] arr, int size, int x, int y) {
        if (size == 1) {
            arr[x][y] = '*';
            return;
        }

        int subSize = size / 3;
        // Fill 3x3 grid with stars and spaces
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    fillSpace(arr, subSize, x + i * subSize, y + j * subSize);
                } else {
                    fillPattern(arr, subSize, x + i * subSize, y + j * subSize);
                }
            }
        }
    }

    private static void fillSpace(char[][] arr, int size, int x, int y) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                arr[i][j] = ' ';
            }
        }
    }
}
