import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1182_subsequenceSum {
   static int N, S;
   static int[] input;
   static int count;

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      S = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      input = new int[N];
      for (int i = 0; i < N; i++) {
         input[i] = Integer.parseInt(st.nextToken());
      }

      dfs(0, 0);

      System.out.println(count);

   }

   public static void dfs(int idx, int currentSum) {
      // 마지막 원소까지 탐색한 경우 종료
      if (idx == N) {
         return;
      }

      int temp = currentSum;
      currentSum += input[idx];
      // 도착지 ? currentSum == S? -> 할일을 해라
      if (currentSum == S) {
         count++;
      }

      // 갈 수 있으면 다음 원소로 간다!
      dfs(idx + 1, temp); // 포함하지 않는 경우,
      dfs(idx + 1, currentSum); // 포함하는 경우

   }
}