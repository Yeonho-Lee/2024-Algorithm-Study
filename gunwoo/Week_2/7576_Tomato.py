import sys
from collections import deque

M, N = map(int, sys.stdin.readline().split())       #M = col, N = row
graph = [list(map(int, sys.stdin.readline().split())) for _ in range (N)]

queue = deque()
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
days = [[0]*M for _ in range(N)]


for x in range(N):
        for y in range(M):
            if graph[x][y] == 1:
                queue.append((x, y))

def bfs():
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < M:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = 1
                    days[nx][ny] = days[x][y] + 1
                    queue.append((nx, ny))              

    ans = 0

    for i in range(N):
        if 0 in graph[i]:
            return -1
        ans = max(max(days[i]), ans)
    
    return ans

print(bfs())
    