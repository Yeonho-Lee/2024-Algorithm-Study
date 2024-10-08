
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1520_slope {

    static int M, N;
    static int[][] board;
    static int[][] dp;

    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        // M - 세로의 크기, N - 가로의 크기
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        board = new int[M][N];
        dp = new int[M][N];

        // 보드, DP 배열 초기화
        for (int row = 0; row < M; row++) {
            st = new StringTokenizer(br.readLine());
            for (int col = 0; col < N; col++) {
                board[row][col] = Integer.parseInt(st.nextToken());
                dp[row][col] = -1;
            }
        }

        System.out.println(dfs(0, 0));
    }

    // DFS 메서드
    // 도착지점에 도달하면 1 반환 (경로 하나 찾음)
    // 이미 계산된 경로가 있으면 그 값을 반환
    // dp[i][j] : row = i, col = j 인 곳에서 도착점까지 가는 경로의 개수
    static int dfs(int row, int col) {
        if (row == M - 1 && col == N - 1) {
            return 1;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        // 경로 개수 초기화
        dp[row][col] = 0;

        // 상하좌우 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int nr = row + dy[i];
            int nc = col + dx[i];

            // 범위 안, 현재 위치보다 낮으면 이동 -> 탐색
            if (0 <= nr && nr < M && 0 <= nc && nc < N && board[nr][nc] < board[row][col]) {
                dp[row][col] += dfs(nr, nc);
            }
        }

        return dp[row][col];
    }
}