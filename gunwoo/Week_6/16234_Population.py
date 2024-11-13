import sys
from collections import deque

input = sys.stdin.readline

N, L, R = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(row, col):
    q = deque()
    q.append((row, col))
    union = []
    union.append((row, col))

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                if L <= abs(graph[nx][ny] - graph[x][y]) <= R:
                    visited[nx][ny] = True
                    q.append((nx, ny))
                    union.append((nx, ny))

    return union


day = 0
while True:
    visited = [[False] * (N) for _ in range(N)]
    #인구이동이 있는지 없는지 확인하기 위한 변수
    isUnion = False

    for i in range(N):
        for j in range(N):
            if visited[i][j] == False:
                visited[i][j] = True
                unions = bfs(i, j)      #(i, j) 나라와 인구이동이 일어나는 나라들

                if len(unions) > 1:
                    isUnion = True
                    ppl = 0

                    #각 나라별 전체 인구 합
                    for k in range(len(unions)):
                        ppl += graph[unions[k][0]][unions[k][1]]
                    
                    #인구이동 후 각 나라의 인구 업데이트
                    for k in range(len(unions)):
                        graph[unions[k][0]][unions[k][1]] = ppl // len(unions)

    #인구이동 일어나는 나라가 없을 때
    if not isUnion:
        break
    day += 1

print(day)