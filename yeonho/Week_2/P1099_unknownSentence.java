
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P1099_unknownSentence {

    static int INF = 1000_000_000;

    static int numbOfWords;
    static String sentence;
    static String[] words;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // process input
        sentence = br.readLine().trim();
        numbOfWords = Integer.parseInt(br.readLine());
        words = new String[numbOfWords];
        for (int i = 0; i < numbOfWords; i++) {
            words[i] = br.readLine().trim();
        }

        int[] dp = new int[sentence.length() + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        // dp 갱신
        for (int i = 0; i < sentence.length(); i++) {
            if (dp[i] == INF)
                continue;

            // 현재 위치에서 시작하는 모든 단어에 대해 계산
            for (String word : words) {
                int wordLen = word.length();
                if (i + wordLen <= sentence.length()) {
                    String subStr = sentence.substring(i, i + wordLen);
                    int cost = calculateCost(subStr, word);
                    if (cost != -1) {
                        dp[i + wordLen] = Math.min(dp[i + wordLen], dp[i] + cost);
                    }
                }
            }
        }

        System.out.println(dp[sentence.length()] == INF ? -1 : dp[sentence.length()]);

    }

    private static int calculateCost(String subStr, String word) {
        if (subStr.length() != word.length())
            return -1;

        int[] subStrCount = new int[26];
        int[] wordCount = new int[26];

        for (int i = 0; i < subStr.length(); i++) {
            subStrCount[subStr.charAt(i) - 'a']++;
            wordCount[word.charAt(i) - 'a']++;
        }

        if (!Arrays.equals(subStrCount, wordCount))
            return -1;

        int cost = 0;
        for (int i = 0; i < subStr.length(); i++) {
            if (subStr.charAt(i) != word.charAt(i)) {
                cost++;
            }
        }

        return cost;
    }
}
