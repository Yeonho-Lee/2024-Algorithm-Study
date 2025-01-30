package yeonho.Week_19;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class P15681_treeAndQuery {

    static int N, R, Q;
    static List<Integer>[] tree;
    static int[] subtreeSize;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        tree = new ArrayList[N + 1];
        subtreeSize = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            tree[i] = new ArrayList<>();
        }

        // 트리 입력
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(v);
            tree[v].add(u);
        }

        // 서브트리 크기 계산
        computeSubtreeSize(R);

        // 쿼리 처리
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            int queryNode = Integer.parseInt(br.readLine());
            sb.append(subtreeSize[queryNode]).append("\n");
        }
        System.out.print(sb);
    }

    // DFS를 이용한 서브트리 크기 계산
    static int computeSubtreeSize(int node) {
        visited[node] = true;
        int size = 1; // 자기 자신 포함
        for (int child : tree[node]) {
            if (!visited[child]) {
                size += computeSubtreeSize(child);
            }
        }
        subtreeSize[node] = size;
        return size;
    }
}
