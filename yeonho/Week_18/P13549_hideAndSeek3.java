package yeonho.Week_18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class P13549_hideAndSeek3 {
    static int N, K;
    static final int MAX = 100_000;
    static int dist[] = new int[MAX + 1];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 수빈이의 초기 위치
        K = Integer.parseInt(st.nextToken()); // 동생의 초기 위치

        int time = find_sibling(N, K);
        System.out.println(time);
    }

    public static int find_sibling(int n, int k) {
        Arrays.fill(dist, -1);
        Deque<Integer> deque = new ArrayDeque<>();
        dist[n] = 0;
        deque.add(n);

        while (!deque.isEmpty()) {
            int current = deque.poll();
            int next;

            // 동생의 위치에 도달하면 종료
            if (current == k) {
                return dist[k];
            }

            // 순간이동
            next = current * 2;
            if (next <= MAX && dist[next] == -1) {
                dist[next] = dist[current];
                deque.addFirst(next);
            }

            // 걷기
            next = current - 1;
            if (next >= 0 && dist[next] == -1) {
                dist[next] = dist[current] + 1;
                deque.addLast(next);
            }
            // 걷기
            next = current + 1;
            if (next <= MAX && dist[next] == -1) {
                dist[next] = dist[current] + 1;
                deque.addLast(next);
            }
        }

        return -1;
    }

}
