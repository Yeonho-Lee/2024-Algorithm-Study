package yeonho.Week_17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class P1865_wormhole_good {
    static class Edge {
        int from, to, weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int TC = Integer.parseInt(br.readLine()); // 테스트 케이스 개수

        for (int t = 0; t < TC; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); // 지점 수
            int M = Integer.parseInt(st.nextToken()); // 도로 수
            int W = Integer.parseInt(st.nextToken()); // 웜홀 수

            List<Edge> edges = new ArrayList<>();
            boolean[] visited = new boolean[N + 1]; // 방문 여부 체크

            // 도로 정보 (양방향)
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, T));
                edges.add(new Edge(E, S, T));
            }

            // 웜홀 정보 (단방향)
            for (int i = 0; i < W; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, -T)); // 시간 감소를 음수로 표현
            }

            boolean isMinusCycle = false;

            // 모든 노드에서 벨만-포드 실행
            for (int i = 1; i <= N; i++) {
                if (!visited[i]) {
                    if (bellmanFord(N, edges, i, visited)) {
                        isMinusCycle = true;
                        break;
                    }
                }
            }

            if (isMinusCycle) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }

        System.out.print(sb.toString());
    }

    static boolean bellmanFord(int N, List<Edge> edges, int start, boolean[] visited) {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        // N-1번 완화 작업
        for (int i = 1; i < N; i++) {
            boolean updated = false;
            for (Edge edge : edges) {
                if (dist[edge.from] != Integer.MAX_VALUE && dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                    updated = true;
                }
            }
            if (!updated)
                break; // 더 이상 갱신이 없으면 중단
        }

        // 방문 처리
        for (int i = 1; i <= N; i++) {
            if (dist[i] != Integer.MAX_VALUE) {
                visited[i] = true;
            }
        }

        // 음수 사이클 존재 여부 확인
        for (Edge edge : edges) {
            if (dist[edge.from] != Integer.MAX_VALUE && dist[edge.from] + edge.weight < dist[edge.to]) {
                return true; // 음수 사이클 존재
            }
        }

        return false; // 음수 사이클 없음
    }
}
