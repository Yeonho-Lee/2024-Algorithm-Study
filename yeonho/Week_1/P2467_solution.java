
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P2467_solution {
    static int N;
    static int[] A;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        processInput();

        int[] result = findClosestToZero(A);

        System.out.println(result[0] + " " + result[1]);
    }

    public static void processInput() throws IOException {
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static int[] findClosestToZero(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        int closestSum = Integer.MAX_VALUE;
        int[] bestPair = new int[2];

        while (left < right) {
            int currentSum = arr[left] + arr[right];

            if (Math.abs(currentSum) < Math.abs(closestSum)) {
                closestSum = currentSum;
                bestPair[0] = arr[left];
                bestPair[1] = arr[right];
            }

            if (currentSum > 0) {
                right--;
            } else if (currentSum < 0) {
                left++;
            } else {
                break;
            }
        }
        return bestPair;
    }
}