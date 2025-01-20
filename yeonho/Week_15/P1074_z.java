package yeonho.Week_15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1074_z {
    static int N, r, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        System.out.println(zOrder(N, r, c));
    }

    public static int zOrder(int N, int r, int c) {
        if (N == 0) {
            return 0;
        }

        int half = 1 << (N - 1); // 2^(n-1)
        int areaSize = half * half;

        if (r < half && c < half) {
            // 1st quadrant
            return zOrder(N - 1, r, c);
        } else if (r < half && c >= half) {
            // 2nd quadrant
            return areaSize + zOrder(N - 1, r, c - half);
        } else if (r >= half && c < half) {
            // 3rd quadrant
            return 2 * areaSize + zOrder(N - 1, r - half, c);
        } else {
            // 4th quadrant
            return 3 * areaSize + zOrder(N - 1, r - half, c - half);
        }
    }
}
