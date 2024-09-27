import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

// The main method must be in a class named "Main".
public class P1062_teach {
	static int max = 0;
	static int N, K;
	static String[] words;
	static boolean[] visited = new boolean[26];
	static int chosen = 5;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] input = br.readLine().trim().split(" ");
		N = Integer.parseInt(input[0]);
		K = Integer.parseInt(input[1]);

		// read the words
		words = new String[N];
		for (int i = 0; i < N; i++) {
			words[i] = br.readLine();
		}

		if (K < 5) {
			bw.write("0");
			bw.flush();
			br.close();
			bw.close();
			return;
		}

		// choose K alphabets including a, n, t, i, c (K-5)

		visited['a' - 'a'] = true;
		visited['c' - 'a'] = true;
		visited['i' - 'a'] = true;
		visited['n' - 'a'] = true;
		visited['t' - 'a'] = true;
		for (int i = 0; i < 26; i++) {
			if (visited[i] == false) {
				dfs('a' + i);
			}
		}

		bw.write(Integer.toString(max));
		bw.flush();
		br.close();
		bw.close();
	}

	static void dfs(int current) {
		// 1. 체크인 -
		// 2. 목적지? - 알파벳이 K개인가? -> max 갱신
		if (chosen == K) {
			// check N words - can be read by students?
			max = Math.max(max, countWords());
		}
		// 3. 연결된 곳 순회 - 현재보다 다음 거 ~ Z까지
		for (int i = current; i <= 'z'; i++) {
			// 4. 갈 수 있는가? - not visited?
			if (!visited[i - 'a']) {
				// 5. 간다 - dfs 호출
				visited[i - 'a'] = true;
				chosen++;
				dfs(i + 1);
				visited[i - 'a'] = false;
				chosen--;
			}
		}
		// 6. 체크아웃 -
	}

	static int countWords() {
		int count = 0;
		for (int i = 0; i < N; i++) {
			String word = words[i];
			for (int j = 0; j < word.length(); j++) {
				if (!visited[word.charAt(j) - 'a']) {
					break;
				}
				if (j == word.length() - 1 && visited[word.charAt(j) - 'a']) {
					count++;
				}
			}
		}
		return count;
	}
}