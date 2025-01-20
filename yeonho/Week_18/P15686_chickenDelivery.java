package yeonho.Week_18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class P15686_chickenDelivery {
    static int N, M; // 도시가 몇 줄? / 치킨집의 max 개수
    static int chickenDistance = 1000_000;
    static int[][] city;
    static List<Position> chickens;
    static List<Position> houses;
    static boolean[] visited = new boolean[13];

    static class Position {
        int y;
        int x;

        public Position(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return "Position [y=" + y + ", x=" + x + "]";
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        city = new int[N][N];
        houses = new ArrayList<>();
        chickens = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                city[i][j] = Integer.parseInt(st.nextToken());
                if (city[i][j] == 1) {
                    houses.add(new Position(i, j));
                } else if (city[i][j] == 2) {
                    chickens.add(new Position(i, j));
                }
            }
        }

        // 치킨집 M 개 고르기 -> M개가 되는 순간 치킨 거리 계산

        backtrack(0, 0);
        System.out.println(chickenDistance);
    }

    static void backtrack(int current, int chosen) {
        // 도착지? -> 치킨 거리 계산
        if (chosen == M) {
            calculateChickenDistance();
        }
        // 주변순회
        // 갈 수 있으면 방문표시하고 들어가기!
        for (int i = current; i < chickens.size(); i++) {
            visited[i] = true;
            backtrack(i + 1, chosen + 1);
            visited[i] = false;
        }

    }

    static void calculateChickenDistance() {
        int tempChickenDistance = 0;
        for (int i = 0; i < houses.size(); i++) {
            Position house = houses.get(i);
            int minDistance = 2 * N;
            for (int j = 0; j < chickens.size(); j++) {
                if (visited[j]) {
                    Position chicken = chickens.get(j);
                    minDistance = Math.min(minDistance, distance(house, chicken));
                }
            }
            tempChickenDistance += minDistance;
        }
        chickenDistance = Math.min(chickenDistance, tempChickenDistance);
    }

    static int distance(Position a, Position b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }

}
