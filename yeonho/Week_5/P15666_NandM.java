import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P15666_NandM {
    static int N, M;
    static int[] numbers;
    static int[] result;
    static boolean[] visited;
    static StringBuilder sb = new StringBuilder();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        numbers = new int[N];
        result = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        // 오름차순 정렬 - 사전순 출력 위함
        Arrays.sort(numbers);

        backtrack(0, 0);

        System.out.println(sb);
    }

    public static void backtrack(int start, int depth) {
        // 1. 도착?
        if (depth == M) {
            for (int i = 0; i < M; i++) {
                sb.append(result[i]).append(" ");
            }
            sb.append("\n");
            return;
        }
        int prev = -1;
        // 2. iterate
        for (int i = start; i < N; i++) {
            // can go in?
            if (numbers[i] != prev) {
                // check in
                prev = numbers[i];
                result[depth] = numbers[i];
                // go!
                backtrack(i, depth + 1);
                // check out
            }

        }
    }
}
