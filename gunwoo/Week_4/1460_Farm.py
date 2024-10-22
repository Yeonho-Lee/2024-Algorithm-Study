import sys
# from itertools import combinations

input = sys.stdin.readline
N, M = map(int, input().split())

seed = []
for _ in range (M):
    seed.append(list(map(int, input().split())))

farm = [[0] * N for _ in range(N)]
fruits = []

for s in seed:
    x, y, l, f = s[0], s[1], s[2], s[3]
    fruits.append(f)
    for i in range(x, x+l):
        farm[i][y:y+l] = [f] * l

def find_square(fruit1, fruit2):
    dp = [[0] * N for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if farm[i][j] == fruit1 or farm[i][j] == fruit2:
                dp[i][j] = 1

    for i in range(1, N):
        for j in range(1, N):
            if dp[i][j] == 1:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    
    return max(map(max, dp)) ** 2

ans = 0
if len(fruits) == 1:
    for i in range(N):
        for j in range(N):
            if farm[i][j]:
                ans += 1
else:
    # for fruit in combinations(fruits, 2):
    #     ans = max(ans, find_square(fruit[0], fruit[1]))
    for i in range(1, 8):
        for j in range(i+1, 8):
            ans = max(ans, find_square(i, j))

print(ans)