
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P1253_Good {
    static int N;
    static int[] A;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        processInput();
        int result = countGoodNumbers();
        System.out.println(result);
    }

    public static void processInput() throws IOException {
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static int countGoodNumbers() {
        Arrays.sort(A);
        int goodCount = 0;
        for (int i = 0; i < N; i++) {
            int left = 0;
            int right = N - 1;

            while (left < right) {

                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }
                int sum = A[left] + A[right];

                if (sum == A[i]) {
                    goodCount++;
                    break;
                } else if (sum < A[i]) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return goodCount;
    }
}
