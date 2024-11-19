package yeonho.Week_9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P20304_makingPassword {

    private static class Node {
        int n, count;

        public Node(int n, int count) {
            this.n = n;
            this.count = count;
        }

        @Override
        public String toString() {
            return "Node [n=" + n + ", count=" + count + "]";
        }

    }

    static int N; // 0 - 1_000_000
    static int M; // 1 - 100_000
    static int result;
    static int[] attemptedPasswords; // 0 - N
    static Queue<Node> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        init();

        for (int i = 0; i < M; i++) {
            int temp = Integer.parseInt(st.nextToken());
            queue.offer(new Node(temp, 0));
            attemptedPasswords[temp] = 0;
        }
        bfs();
        System.out.println(result);

    }

    private static void bfs() {
        while (!queue.isEmpty()) {
            Node n = queue.poll();
            for (int i = 1; i <= N; i <<= 1) {
                isPossible(n, (n.n & i) > 0 ? (n.n - i) : (n.n + i));
            }
        }
    }

    private static void isPossible(Node n, int num) {
        if (num <= N && attemptedPasswords[num] == -1) {
            attemptedPasswords[num] = n.count + 1;
            queue.add(new Node(num, n.count + 1));
            result = Math.max(result, n.count + 1);
        }
    }

    private static void init() {
        attemptedPasswords = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            attemptedPasswords[i] = -1;
        }
    }
}
