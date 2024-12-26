import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
graph = [list(input().strip()) for _ in range(N)]
visited = [[False]*N for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# def bfs(i, j):
#     q = deque()
#     q.append((i, j))
#     visited[i][j] = True
#     while q:
#         x, y = q.popleft()
#         for i in range(4):
#             nx = x + dx[i]
#             ny = y + dy[i]
#             if 0 <= nx < N and 0 <= ny < N:
#                 if graph[nx][ny] == graph[x][y] and not visited[nx][ny]:
#                     q.append((nx, ny))
#                     visited[nx][ny] = True

def dfs(x, y):
    visited[x][y] = True
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < N and 0 <= ny < N:
            if graph[nx][ny] == graph[x][y] and not visited[nx][ny]:
                dfs(nx, ny)


not_blind = 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            dfs(i, j)
            not_blind += 1

blind = 0
for i in range(N):
    for j in range(N):
        if graph[i][j] == 'R':
            graph[i][j] = 'G'

visited = [[False]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            dfs(i, j)
            blind += 1

print(not_blind, blind)
                

