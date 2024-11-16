package yeonho.Week_9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class P9328_key {

    static class Position {
        int h, w;

        public Position(int h, int w) {
            this.h = h;
            this.w = w;
        }

        @Override
        public String toString() {
            return "Position [h=" + h + ", w=" + w + "]";
        }

    }

    static int T, H, W;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            char[][] map = new char[H][W];
            for (int h = 0; h < H; h++) {
                String line = br.readLine();
                for (int w = 0; w < W; w++) {
                    map[h][w] = line.charAt(w);
                }
            }
            // keys
            boolean[] keys = new boolean[26];
            String line = br.readLine();
            for (int i = 0; i < line.length(); i++) {
                if (line.charAt(0) == '0') {
                    break;
                }
                int key = line.charAt(i) - 'a';
                keys[key] = true;
            }
            System.out.println(bfs(map, keys));
        }

    }

    static int bfs(char[][] map, boolean[] hasKey) {
        // keys를 발견했을 때 queue에 door를 다시 포함시켜주기 위한 array
        List<Position>[] doors = new ArrayList[26];
        for (int i = 0; i < doors.length; i++) {
            doors[i] = new ArrayList<>();
        }
        Queue<Position> queue = new LinkedList<>();
        int documents = 0;
        int[] dh = { -1, 1, 0, 0 };
        int[] dw = { 0, 0, -1, 1 };
        boolean[][] visited = new boolean[H][W];

        // initialize queue - 가장자리 탐색
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (h == 0 || h == H - 1 || w == 0 || w == W - 1) {
                    int cell = map[h][w];
                    if (visited[h][w]) {
                        continue;
                    }
                    if (cell == '.') {
                        visited[h][w] = true;
                        queue.offer(new Position(h, w));
                    } else if ('A' <= cell && cell <= 'Z') {
                        int door = cell - 'A';
                        if (hasKey[door]) {
                            visited[h][w] = true;
                            queue.offer(new Position(h, w));
                        } else {
                            doors[door].add(new Position(h, w));
                        }
                    } else if ('a' <= cell && cell <= 'z') {
                        int key = cell - 'a';
                        visited[h][w] = true;
                        hasKey[key] = true;
                        queue.offer(new Position(h, w));
                        if (doors[key] != null) {
                            List<Position> door = doors[key];
                            for (int d = 0; d < door.size(); d++) {
                                Position p = door.get(d);
                                queue.offer(p);
                            }
                            door.clear();
                        }
                    } else if (cell == '$') {
                        documents++;
                        visited[h][w] = true;
                        queue.offer(new Position(h, w));
                    }
                }
            }
        }

        while (!queue.isEmpty()) {
            Position current = queue.poll();
            // System.out.println(current);

            for (int i = 0; i < 4; i++) {
                int nh = current.h + dh[i];
                int nw = current.w + dw[i];

                if (isInBound(nh, nw) && !visited[nh][nw]) {
                    visited[nh][nw] = true;
                    char nextCell = map[nh][nw];
                    if (nextCell == '.') {
                        // 빈 공간 -> 들어간다
                        queue.offer(new Position(nh, nw));
                    } else if (nextCell == '*') {
                        // 벽 -> 그냥 지나감
                        continue;
                    } else if (nextCell == '$') {
                        // 문서라면
                        queue.offer(new Position(nh, nw));
                        documents++;
                    } else if ('a' <= nextCell && nextCell <= 'z') {
                        // 열쇠라면 -> 열쇠를 더해주고 queue도 더해준다.
                        int key = nextCell - 'a';
                        hasKey[key] = true;
                        queue.offer(new Position(nh, nw));
                        // 지날 수 있는 문이 이전에 있었다면 queue에 더해준다.
                        if (doors[key] != null) {
                            List<Position> door = doors[key];
                            for (int d = 0; d < door.size(); d++) {
                                Position p = door.get(d);
                                queue.offer(p);
                            }
                            door.clear();
                        }
                    } else if ('A' <= nextCell && nextCell <= 'Z') {
                        // 문이라면
                        // 1. 열쇠 O - 열고 들어감
                        // 2. 열쇠 X - 위치에 더해줌
                        int door = nextCell - 'A';
                        if (hasKey[door]) {
                            queue.offer(new Position(nh, nw));
                        } else {
                            doors[door].add(new Position(nh, nw));
                        }
                    }
                }
            }
        }
        return documents;
    }

    static boolean isInBound(int nh, int nw) {
        if (0 <= nh && nh < H && 0 <= nw && nw < W) {
            return true;
        }
        return false;
    }
}
