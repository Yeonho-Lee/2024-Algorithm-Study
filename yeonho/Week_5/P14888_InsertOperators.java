import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P14888_InsertOperators {
    static int N;
    static int[] numbers;
    static int[] operators = new int[4];
    // 0 - (+), 1 - (-), 2 - (x), 3 - (/)
    static int minResult = 1000_000_000;
    static int maxResult = -1000_000_000;

    public static void main(String[] args) throws IOException {
        // process input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        numbers = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            operators[i] = Integer.parseInt(st.nextToken());
        }

        // process
        backtrack(0, numbers[0]);

        System.out.println(maxResult);
        System.out.println(minResult);
    }

    static void backtrack(int n, int result) {
        // destination?
        if (n == N - 1) {
            minResult = Math.min(minResult, result);
            maxResult = Math.max(maxResult, result);
            return;
        }

        // loop
        for (int i = 0; i < 4; i++) {
            // Can go?
            if (operators[i] > 0) {
                // check in
                operators[i]--;
                int tempResult = result;
                switch (i) {
                    case 0: // +
                        tempResult += numbers[n + 1];
                        break;
                    case 1:
                        tempResult -= numbers[n + 1];
                        break;
                    case 2:
                        tempResult *= numbers[n + 1];
                        break;
                    case 3:
                        tempResult /= numbers[n + 1];
                        break;
                    default:
                        break;
                }
                // go
                backtrack(n + 1, tempResult);
                // check out
                operators[i]++;
            }
        }
    }
}
