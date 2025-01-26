package yeonho.Week_09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P17071_hideAndSeek5 {

    static int N, K;

    static class Position {
        int pos;
        int time;

        public Position(int pos, int time) {
            this.pos = pos;
            this.time = time;
        }

        @Override
        public String toString() {
            return "Position [pos=" + pos + ", time=" + time + "]";
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        System.out.println(find_sibling());
    }

    static int find_sibling() {
        Queue<Position> subinQueue = new LinkedList<>();
        int max_limit = 50_0000;
        boolean[][] visited = new boolean[500000 + 1][2];
        subinQueue.offer(new Position(N, 0));
        visited[N][0] = true;
        int sibling = K;
        int time = 0;
        while (!subinQueue.isEmpty()) {
            int size = subinQueue.size();

            for (int i = 0; i < size; i++) {
                Position subin = subinQueue.poll();

                // 동생을 찾은 경우 시간 return
                if (sibling > max_limit)
                    return -1;
                if (visited[sibling][subin.time % 2])
                    return subin.time;
                // 2초에 x=3을 방문했으면
                // 3초 x=4
                // 4초 x=3

                int[] nextPos = { subin.pos + 1, subin.pos - 1, subin.pos * 2 };
                for (int j = 0; j < 3; j++) {

                    if (isNotRange(nextPos[j]))
                        continue;
                    if (!visited[nextPos[j]][(subin.time + 1) % 2]) {
                        visited[nextPos[j]][(subin.time + 1) % 2] = true;
                        subinQueue.offer(new Position(nextPos[j], subin.time + 1));
                    }
                }
            }

            // 동생이 맵을 벗어나면 못찾으므로 return -1
            if (sibling > max_limit)
                return -1;
            // 동생 이동
            sibling += ++time;
        }
        return -1;
    }

    static boolean isNotRange(int x) {
        return (x < 0 || x >= 500001) ? true : false;
    }
}
