import sys

N, M = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

residual = [0 for _ in range(M)]
prefix_sum = 0

for i in range(N):
    prefix_sum += nums[i]
    residual[prefix_sum % M] += 1

count = residual[0]

for r in residual:
    count += r*(r-1)//2

print(count)