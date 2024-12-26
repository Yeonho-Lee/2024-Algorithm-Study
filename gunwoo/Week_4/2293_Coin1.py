import sys

input = sys.stdin.readline
N, K = map(int, input().split())

dp = [0] * (K+1)
dp[0] = 1
coin = []
for i in range(N):
    coin.append(int(input()))

for i in range(N):
    if i == 0:
        for j in range(coin[i], K+1, coin[i]):
            dp[j] = 1
    else:
        for j in range(coin[i], K+1):
            dp[j] += dp[j - coin[i]]


print(dp)