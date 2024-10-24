import sys
from collections import defaultdict

input = sys.stdin.readline
N = int(input())
graph = [[0] * N for _ in range(N)]
students = [list(map(int, input().split())) for _ in range(N**2)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
stu_dict = defaultdict(list)

for s in students:
    stu_dict[s[0]] = s[1:]
    seats = []

    for i in range(N):
        for j in range(N):
            if graph[i][j] == 0:
                like = 0
                empty_seat = 0
                for k in range(4):
                    nx = i + dx[k]
                    ny = j + dy[k]

                    if 0 <= nx < N and 0 <= ny < N:
                        if graph[nx][ny] in stu_dict[s[0]]:
                            like += 1
                        
                        if graph[nx][ny] == 0:
                            empty_seat += 1

                seats.append((like, empty_seat, i, j))

    seats.sort(key = lambda x: (-x[0], -x[1], x[2], x[3]))         #like -> empty -> i 작은거 -> j 작은거
    graph[seats[0][2]][seats[0][3]] = s[0]

answer = 0
satisfy = {0: 0, 1: 1, 2: 10, 3: 100, 4: 1000}

for i in range(N):
    for j in range(N):
        student = graph[i][j]
        count = 0
        for k in range(4):
            nx = i + dx[k]
            ny = j + dy[k]

            if 0 <= nx < N and 0 <= ny < N:
                if graph[nx][ny] in stu_dict[student]:
                    count += 1
        
        answer += satisfy[count]

print(answer)