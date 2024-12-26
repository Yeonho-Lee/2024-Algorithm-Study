import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P9663_NQueens {
	static int N;
	static int count = 0;
	static int[] Queens;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		Queens = new int[N];
		dfs(0);
		System.out.println(count);
	}
	
	static void dfs(int row) {
		if (row == N) {
			count++;
		}
		for (int col = 0; col < N; col++) {
			if (canGo(row, col)) {
				Queens[row] = col;
				dfs(row + 1);
			}
		}
	}
	
	static boolean canGo(int row, int col) {
		for (int r = 0; r < row; r++) {
			if (col == Queens[r] || Math.abs(row-r) == Math.abs(col - Queens[r])) return false;
		}
		return true;
	}

}
