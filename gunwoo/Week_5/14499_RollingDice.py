import sys

input = sys.stdin.readline

N, M, x, y, K = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
command = list(map(int, input().split()))

dice = {'U': 0, 'D': 0, 'E': 0, 'W': 0, 'S': 0, 'N': 0}

def rolling(direction):
    #동
    if direction == 1:
        #남, 북 그대로
        dice['U'], dice['D'], dice['E'], dice['W'] = dice['W'], dice['E'], dice['U'], dice['D']
    #서
    if direction == 2:
        #남, 북 그대로
        dice['U'], dice['D'], dice['E'], dice['W'] = dice['E'], dice['W'], dice['D'], dice['U']
    #북
    if direction == 3:
        #동, 서 그대로
        dice['U'], dice['D'], dice['S'], dice['N'] = dice['S'], dice['N'], dice['D'], dice['U']
    #남
    if direction == 4:
        #동, 서 그대로
        dice['U'], dice['D'], dice['S'], dice['N'] = dice['N'], dice['S'], dice['U'], dice['D']

#동, 서, 북, 남 = 1, 2, 3, 4
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

for c in command:
    x += dx[c-1]
    y += dy[c-1]
    if 0 <= x < N and 0 <= y < M:
        rolling(c)
        if graph[x][y] != 0:
            dice['D'] = graph[x][y]
            graph[x][y] = 0
        else:
            graph[x][y] = dice['D']

        print(dice['U'])
    
    else:
        x -= dx[c-1]
        y -= dy[c-1]