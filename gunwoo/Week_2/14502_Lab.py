import sys
from collections import deque
from copy import deepcopy

R, C = map(int, sys.stdin.readline().split())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(R)]

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
ans = 0

def bfs():
    queue = deque()
    temp_graph = deepcopy(graph)

    for x in range(R):
        for y in range(C):
            if temp_graph[x][y] == 2:
                queue.append((x,y))
    
    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < R and 0 <= ny < C:
                if temp_graph[nx][ny] == 0:
                    queue.append((nx, ny))
                    temp_graph[nx][ny] = 2

    global ans
    zero_count = 0

    for i in range(R):
        zero_count += temp_graph[i].count(0)

    ans = max(zero_count, ans)

#백트래킹
def make_wall(wall_num):
    if wall_num == 3:
        bfs()
        return
    
    for x in range(R):
        for y in range(C):
            if graph[x][y] == 0:
                graph[x][y] = 1
                make_wall(wall_num+1)
                graph[x][y] = 0

make_wall(0)
print(ans)
