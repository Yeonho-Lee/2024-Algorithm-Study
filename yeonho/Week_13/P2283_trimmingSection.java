package yeonho.Week_13;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P2283_trimmingSection {
    static int N;
    static long K;
    static int[][] intervals;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        intervals = new int[N][2];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            intervals[i][0] = Integer.parseInt(st.nextToken()); // start
            intervals[i][1] = Integer.parseInt(st.nextToken()); // end
        }

        // 구간 정렬 (시작점을 기준으로 정렬)
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        // 결과를 저장할 A와 B
        int bestA = 0, bestB = 0;

        // 투 포인터 알고리즘
        int left = 0, right = 0;
        long currentLength = 0;

        while (right <= 1_000_000) {
            // 현재 구간에서 총 길이 계산
            currentLength = calculateLength(intervals, left, right);

            if (currentLength < K) {
                // 길이가 부족하면 오른쪽 포인터 확장
                right++;
            } else if (currentLength > K) {
                // 길이가 초과하면 왼쪽 포인터 축소
                left++;
            } else {
                // 조건을 만족하는 경우 결과 갱신
                if (bestA == 0 || left < bestA || (left == bestA && right < bestB)) {
                    bestA = left;
                    bestB = right;
                }
                right++; // 더 작은 B를 찾기 위해 오른쪽 포인터 이동
            }
        }

        // 결과 출력
        if (bestA == 0 && bestB == 0) {
            System.out.println("0 0");
        } else {
            System.out.println(bestA + " " + bestB);
        }
    }

    public static long calculateLength(int[][] intervals, int A, int B) {
        long total = 0;

        // 각 구간에서 [A, B]에 포함되는 길이 계산
        for (int[] interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            total += Math.max(0, Math.min(B, end) - Math.max(A, start));
        }
        return total;
    }
}