import sys
from collections import deque

#input data
input = sys.stdin.readline
N, M = map(int, input().split())
r, c, pos = map(int, input().split())     #pos: (0, 1, 2, 3) = (북, 동, 남, 서)
graph = []
for i in range(N):
    graph.append(list(map(int, input().split())))

cleaned = [[False] * M for _ in range(N)]
q = deque()
q.append((r, c))
dx = [-1, 0, 1, 0]      #북, 동, 남, 서 순으로
dy = [0, 1, 0, -1]

answer = 1
cleaned[r][c] = True

while q:
    x, y = q.popleft()
    clean_area = 0
    
    for _ in range(4):
        pos = (pos - 1) % 4     #첫 방향에서 반시계 방향으로 회전
        nx = x + dx[pos]
        ny = y + dy[pos]

        if 0 <= nx < N and 0 <= ny < M and graph[nx][ny] != 1:
            if not cleaned[nx][ny]:
                q.append((nx, ny))
                cleaned[nx][ny] = True
                answer += 1
                clean_area = 1
                break
        
    if clean_area == 0:
        if graph[x - dx[pos]][y - dy[pos]] != 1:
            q.append((x - dx[pos], y - dy[pos]))        #후진
        
        else:
            break

print(answer)