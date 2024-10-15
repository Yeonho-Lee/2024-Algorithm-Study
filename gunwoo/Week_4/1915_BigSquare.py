import sys

input = sys.stdin.readline
N, M = map(int, input().split())

arr = []
for _ in range(N):
    arr.append(list(map(int, list(input().rstrip()))))

ans = 0
dp = [[0] * M for _ in range(N)]

for i in range(N):
    for j in range(M):
        if i == 0 or j == 0:
            dp[i][j] = arr[i][j]
        elif arr[i][j] == 1:
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            
ans = max(map(max, dp))
print(ans ** 2)