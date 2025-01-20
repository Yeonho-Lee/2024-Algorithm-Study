package yeonho.Week_15;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class P11729_hanoi {

    public static void solveHanoi(int n, int start, int end, int temp, BufferedWriter bw) throws IOException {
        if (n == 1) {
            bw.write(start + " " + end + "\n");
            return;
        }
        // Move n-1 disks from start to temp
        solveHanoi(n - 1, start, temp, end, bw);
        // Move the nth disk from start to end
        bw.write(start + " " + end + "\n");
        // Move n-1 disks from temp to end
        solveHanoi(n - 1, temp, end, start, bw);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = sc.nextInt();

        System.out.println((1 << n) - 1);

        solveHanoi(n, 1, 3, 2, bw);

        sc.close();
        bw.close();
    }
}
