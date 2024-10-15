import sys

input = sys.stdin.readline
T =  int(input())

dp = [1] * 10001

#1, 2만으로 만들 수 있는 경우의 수
for i in range(2, 10001):
    dp[i] += dp[i-2]

#1, 2, 3으로 만들 수 있는 경우의 수
for i in range(3, 10001):
    dp[i] += dp[i-3]

for _ in range(T):
    n = int(input())
    print(dp[n])