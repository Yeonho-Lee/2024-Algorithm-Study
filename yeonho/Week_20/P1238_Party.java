package yeonho.Week_20;

import java.io.*;
import java.util.*;

public class P1238_Party {
    static int N, M, X; // N: 마을 개수, M: 도로 개수, X: 파티가 열리는 마을
    static List<int[]>[] graph;
    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 입력값 처리
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken()) - 1; // 0-indexed 변환

        graph = new ArrayList[N];
        for (int i = 0; i < N; i++)
            graph[i] = new ArrayList<>();

        // 도로 정보 입력
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            int t = Integer.parseInt(st.nextToken());
            graph[u].add(new int[] { v, t }); // 단방향 도로
        }

        int maxTime = 0; // 최장 소요 시간 저장 변수
        for (int i = 0; i < N; i++) {
            if (i == X)
                continue; // 파티가 열리는 마을 제외
            int go = dijkstra(i, X); // 마을 i에서 X까지 가는 최단 거리
            int back = dijkstra(X, i); // X에서 마을 i까지 돌아오는 최단 거리
            maxTime = Math.max(maxTime, go + back); // 가장 오래 걸리는 학생 찾기
        }

        System.out.println(maxTime); // 결과 출력
    }

    // 다익스트라 알고리즘을 이용한 최단 경로 탐색
    static int dijkstra(int start, int end) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        int[] dist = new int[N];
        Arrays.fill(dist, INF);
        dist[start] = 0;
        pq.offer(new int[] { start, 0 });

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int node = curr[0], d = curr[1];
            if (d > dist[node])
                continue; // 이미 처리된 노드는 스킵

            for (int[] next : graph[node]) {
                int nextNode = next[0], weight = next[1];
                if (dist[nextNode] > dist[node] + weight) {
                    dist[nextNode] = dist[node] + weight;
                    pq.offer(new int[] { nextNode, dist[nextNode] }); // 우선순위 큐에 추가
                }
            }
        }
        return dist[end]; // 목적지까지의 최단 거리 반환
    }
}
