package yeonho.Week_18;

import java.util.Scanner;

/*
*                n
*       | 1   1 |    | F(n+1)  F(n)  |
* A^n = |       |  = |               |
*       | 1   0 |    |  F(n)  F(n-1) |
*/

public class P11444_fibonacci6 {
    static long n;
    final static long MOD = 1_000_000_007;
    public static long[][] E = { { 1, 1 }, { 1, 0 } };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();

        System.out.println(fibo(n));
    }

    static long fibo(long n) {
        long[][] matrix = matrixPower(E, n - 1);
        return matrix[0][0];
    }

    static long[][] matrixPower(long[][] A, long exp) {
        if (exp == 0 || exp == 1) {
            return A;
        }

        // 절반으로 분할하여 재귀호출
        long[][] temp = matrixPower(A, exp / 2);
        temp = multiplyMatrices(temp, temp);
        if (exp % 2 == 1) {
            temp = multiplyMatrices(A, temp);
        }

        return temp;
    }

    static long[][] multiplyMatrices(long[][] a, long[][] b) {
        long[][] result = new long[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
            }
        }
        return result;
    }
}
