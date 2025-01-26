package yeonho.Week_04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class P1941_7pricesses {
    static char[][] map = new char[5][5];
    static boolean[][] visited = new boolean[5][5];
    static int result = 0;

    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 5; i++) {
            String line = br.readLine().trim();
            for (int j = 0; j < 5; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        // 25명 중 7명을 선택하는 조합 생성
        backtrack(new ArrayList<>(), 0, 0);

        // 결과 출력
        System.out.println(result);
    }

    // 백트래킹: 25명 중 7명을 선택하는 조합을 생성
    static void backtrack(List<int[]> selected, int start, int count) {
        if (count == 7) { // 7명 선택 완료 시
            if (isValid(selected)) { // 조건을 만족하는지 체크
                result++;
            }
            return;
        }

        for (int i = start; i < 25; i++) {
            int x = i / 5;
            int y = i % 5;
            selected.add(new int[] { x, y }); // 학생 선택
            backtrack(selected, i + 1, count + 1); // 재귀 호출
            selected.remove(selected.size() - 1); // 선택 취소 (백트래킹)
        }
    }

    // 조건을 만족하는지 확인: BFS로 연결 여부와 'S' 학생 수 체크
    static boolean isValid(List<int[]> selected) {
        int sCount = 0; // 'S' 학생 수

        visited = new boolean[5][5];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(selected.get(0)); // 첫 번째 학생으로 BFS 시작
        visited[selected.get(0)[0]][selected.get(0)[1]] = true;

        int connected = 1; // 연결된 학생 수

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1];

            if (map[x][y] != 'S') {
            } else {
                sCount++; // 'S' 학생 수 증가
            } // 'S' 학생 수 증가

            // 4방향 탐색
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 범위 내에 있고, 방문하지 않았으며 선택된 학생일 경우
                if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visited[nx][ny]) {
                    for (int[] student : selected) {
                        if (student[0] == nx && student[1] == ny) {
                            visited[nx][ny] = true;
                            queue.add(new int[] { nx, ny });
                            connected++;
                            break;
                        }
                    }
                }
            }
        }

        // 7명이 모두 연결되었고 'S' 학생이 4명 이상인 경우
        return connected == 7 && sCount >= 4;
    }
}