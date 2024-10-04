import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class P16500_String {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        String S = br.readLine();
        int len = S.length();
        int N = Integer.parseInt(br.readLine());

        Set<String> wordSet = new HashSet<>();
        for (int i = 0; i < N; i++) {
            wordSet.add(br.readLine());
        }

        // DP 배열 초기화
        boolean[] dp = new boolean[len + 1];
        dp[0] = true; // 빈 문자열은 만들 수 있음

        // 동적 계획법(DP) 적용
        for (int i = 0; i <= len; i++) {
            if (dp[i]) { // 현재 i까지의 문자열을 만들 수 있는 경우
                for (int j = i + 1; j <= len; j++) {
                    if (wordSet.contains(S.substring(i, j))) {
                        dp[j] = true; // i에서 j까지의 부분 문자열이 단어 목록에 있는 경우
                    }
                }
            }
        }

        // 결과 출력
        if (dp[len]) {
            System.out.println(1); // S를 만들 수 있으면 1
        } else {
            System.out.println(0); // S를 만들 수 없으면 0
        }
    }
}
