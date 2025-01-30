package yeonho.Week_19;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class P13913_hideAndSeek4 {
    static int N, K;
    static int[] parent = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        if (N == K) {
            System.out.println(0);
            System.out.println(N);
            return;
        }

        bfs();

    }

    static void bfs() {
        Queue<Integer> queue = new LinkedList<>();
        int[] dist = new int[100001]; // 최단 시간 저장 배열
        boolean[] visited = new boolean[100001];

        queue.add(N);
        visited[N] = true;
        dist[N] = 0;

        while (!queue.isEmpty()) {
            int now = queue.poll();

            for (int next : new int[] { now - 1, now + 1, now * 2 }) {
                if (next >= 0 && next <= 100000 && !visited[next]) {
                    queue.add(next);
                    visited[next] = true;
                    dist[next] = dist[now] + 1; // 시간 증가
                    parent[next] = now; // 이전 위치 저장

                    if (next == K) { // 목표에 도달하면 종료
                        System.out.println(dist[next]);
                        printPath(next);
                        return;
                    }
                }
            }
        }
    }

    static void printPath(int end) {
        List<Integer> path = new ArrayList<>();
        for (int i = end; i != N; i = parent[i]) {
            path.add(i);
        }
        path.add(N);
        Collections.reverse(path); // 경로를 올바른 순서로 정렬
        for (int pos : path) {
            System.out.print(pos + " ");
        }
    }
}
