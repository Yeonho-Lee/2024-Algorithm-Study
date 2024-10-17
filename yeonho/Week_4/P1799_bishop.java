package yeonho.Week_4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1799_bishop {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static int maxBlack = 0, maxWhite = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        visited = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 흑칸 탐색 (0열부터 시작하는 흑칸)
        backtrack(0, 0, 0, true);
        // 백칸 탐색 (1열부터 시작하는 백칸)
        backtrack(0, 1, 0, false);

        // 두 값을 합산하여 최대 비숍 수 출력
        System.out.println(maxBlack + maxWhite);
    }

    // 체스판의 흑백 칸에 따라 백트래킹 수행
    static void backtrack(int row, int col, int count, boolean isBlack) {
        // 종료 조건: 탐색이 끝났을 때
        if (row >= N) {
            if (isBlack) {
                maxBlack = Math.max(maxBlack, count);
            } else {
                maxWhite = Math.max(maxWhite, count);
            }
            return;
        }

        // 다음 칸으로 넘어가기 위한 계산
        int nc = col + 2; // 흑백 칸 번갈아가며 탐색
        int nr = row;
        if (nc >= N) {
            nc = (col % 2 == 0) ? 1 : 0; // 다음 행에서 흑백 칸 시작을 번갈아 진행
            nr += 1;
        }

        // 비숍을 놓을 수 있는 경우
        if (map[row][col] == 1 && isValid(row, col)) {
            visited[row][col] = true;
            backtrack(nr, nc, count + 1, isBlack); // 비숍을 놓는 경우
            visited[row][col] = false; // 백트래킹
        }

        // 비숍을 놓지 않고 다음 칸으로 이동
        backtrack(nr, nc, count, isBlack);
    }

    // 현재 위치에 비숍을 놓을 수 있는지 확인하는 함수
    static boolean isValid(int r, int c) {
        // 왼쪽 위 대각선 체크
        for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
            if (visited[r - i][c - i])
                return false;
        }
        // 오른쪽 위 대각선 체크
        for (int i = 1; r - i >= 0 && c + i < N; i++) {
            if (visited[r - i][c + i])
                return false;
        }

        return true;
    }
}
