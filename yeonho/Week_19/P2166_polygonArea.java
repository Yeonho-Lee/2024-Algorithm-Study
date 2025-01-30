package yeonho.Week_19;

import java.util.Scanner;

public class P2166_polygonArea {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] x = new long[N];
        long[] y = new long[N];

        for (int i = 0; i < N; i++) {
            x[i] = sc.nextLong();
            y[i] = sc.nextLong();
        }

        double area = 0;

        // 신발끈 정리 공식 적용
        for (int i = 0; i < N; i++) {
            int j = (i + 1) % N; // 다음 꼭짓점 (마지막 꼭짓점 -> 첫 번째 꼭짓점 연결)
            area += (x[i] * y[j]) - (y[i] * x[j]);
        }

        area = Math.abs(area) / 2.0;

        // 소수점 첫째 자리까지 출력
        System.out.printf("%.1f\n", area);
    }
}