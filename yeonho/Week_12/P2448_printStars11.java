package yeonho.Week_12;

import java.util.Scanner;

public class P2448_printStars11 {
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
        char[][] arr = new char[n][2 * n - 1];
        fillSpace(arr, n, 0, 0);
        fillPattern(arr, n, 0, n - 1);
        return arr;
    }

    private static void fillPattern(char[][] arr, int size, int x, int y) {
        if (size == 3) {
            arr[x][y] = '*';
            arr[x + 1][y - 1] = '*';
            arr[x + 1][y + 1] = '*';
            for (int i = -2; i <= 2; i++) {
                arr[x + 2][y + i] = '*';
            }
            return;
        }

        int subSize = size / 2;
        // Fill 3x3 grid with stars and spaces
        fillPattern(arr, subSize, x, y);
        fillPattern(arr, subSize, x + subSize, y - subSize);
        fillPattern(arr, subSize, x + subSize, y + subSize);
        return;

    }

    private static void fillSpace(char[][] arr, int size, int x, int y) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size * 2 - 1; j++) {
                arr[i][j] = ' ';
            }
        }
    }
}
