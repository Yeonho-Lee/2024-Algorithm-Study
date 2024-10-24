import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P7453_fourNumbers {
    static int n;
    static int[] A, B, C, D;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        A = new int[n];
        B = new int[n];
        C = new int[n];
        D = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            A[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
            C[i] = Integer.parseInt(st.nextToken());
            D[i] = Integer.parseInt(st.nextToken());
        }

        // A와 B의 가능한 모든 합을 저장할 배열
        int[] sumAB = new int[n * n];
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumAB[index++] = A[i] + B[j];
            }
        }

        // C와 D의 가능한 모든 합을 저장할 배열
        int[] sumCD = new int[n * n];
        index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumCD[index++] = C[i] + D[j];
            }
        }

        // sumAB 배열과 sumCD 배열을 정렬
        Arrays.sort(sumAB);
        Arrays.sort(sumCD);

        // 두 배열에서 합이 0이 되는 쌍의 개수 계산
        long count = 0;
        int left = 0;
        int right = sumCD.length - 1;

        while (left < sumAB.length && right >= 0) {
            int sum = sumAB[left] + sumCD[right];

            if (sum == 0) {
                int abCount = 1;
                int cdCount = 1;

                // 같은 값이 여러 번 나타나는 경우, 그 값을 카운트
                while (left + 1 < sumAB.length && sumAB[left] == sumAB[left + 1]) {
                    left++;
                    abCount++;

                }
                while (right - 1 >= 0 && sumCD[right] == sumCD[right - 1]) {
                    right--;
                    cdCount++;
                }

                count += (long) abCount * cdCount;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }

        System.out.println(count);
    }
}
