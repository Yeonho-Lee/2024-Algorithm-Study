package yeonho.Week_9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P20304_makingPassword {

    private static class Node {
        int n, count; // 현재 비밀번호, 안전 거리

        public Node(int n, int count) {
            this.n = n;
            this.count = count;
        }
    }

    static int N; // 가능한 최대 비밀번호
    static int M; // 시도된 비밀번호 개수
    static int result; // 최대 안전도
    static int[] attemptedPasswords; // 방문 체크 및 안전 거리 저장
    static Queue<Node> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        init();

        // BFS 초기화: 시도된 비밀번호들로부터 시작
        for (int i = 0; i < M; i++) {
            int temp = Integer.parseInt(st.nextToken());
            queue.offer(new Node(temp, 0)); // 거리 0부터 시작
            attemptedPasswords[temp] = 0; // 방문 처리
        }

        // BFS 실행
        bfs();

        // 결과 출력
        System.out.println(result);
    }

    private static void init() {
        // 방문 배열을 초기화 (-1은 방문하지 않음을 의미)
        attemptedPasswords = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            attemptedPasswords[i] = -1;
        }
    }

    private static void bfs() {
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            int current = node.n;
            int currentSafety = node.count;

            // 최대 안전도 갱신
            result = Math.max(result, currentSafety);

            // 다음 노드 탐색: XOR 비트를 이용하여 1비트 변경
            for (int i = 1; i <= N; i <<= 1) {
                int next = (current & i) > 0 ? (current - i) : (current + i);
                isPossible(node, next);
            }
        }
    }

    private static void isPossible(Node node, int num) {
        if (num <= N && attemptedPasswords[num] == -1) {
            // 아직 방문하지 않은 비밀번호일 경우
            attemptedPasswords[num] = node.count + 1; // 안전 거리 갱신
            queue.offer(new Node(num, node.count + 1)); // 큐에 추가
        }
    }
}
