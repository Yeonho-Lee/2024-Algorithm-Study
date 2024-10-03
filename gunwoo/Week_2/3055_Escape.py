import sys
from collections import deque

R, C = map(int, sys.stdin.readline().split())
graph = [list(sys.stdin.readline().strip()) for _ in range(R)]

visited = [[0]*C for _ in range(R)]
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
queue = deque()

for x in range(R):
    for y in range(C):
        if graph[x][y] == 'S':
            queue.append((x,y))

for x in range(R):
    for y in range(C):
        if graph[x][y] == '*':
            queue.append((x,y))


def bfs():
    while queue:
        x, y = queue.popleft()
        curr = graph[x][y]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < R and 0 <= ny < C:     #범위 안에 존재하는지 확인
                if graph[nx][ny] == 'X':        #가려는 곳이 바위면 무시
                    continue
                if graph[nx][ny] == '*':        #가려는 곳이 물이면 무시
                    continue
                
                if curr == 'S' and graph[nx][ny] == '.':
                    graph[nx][ny] = 'S'
                    visited[nx][ny] = visited[x][y] + 1
                    queue.append((nx, ny))
                elif curr == '*' and (graph[nx][ny] == '.' or graph[nx][ny] == 'S'):
                    graph[nx][ny] = '*'
                    queue.append((nx, ny))
                elif curr == 'S' and graph[nx][ny] == 'D':
                    visited[nx][ny] = visited[x][y] + 1
                    return visited[nx][ny]

    return "KAKTUS"

print(bfs())