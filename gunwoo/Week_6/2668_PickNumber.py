import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N = int(input())
nums = [0] + [int(input()) for _ in range(N)]
ans = []

def dfs(start, v):
    visited[v] = True
    next = nums[v]
    if not visited[next]:
        dfs(start, next)
    if visited[next] and next == start:
        ans.append(start)

for i in range(1, N+1):
    visited = [False]*(N+1)
    #i = 시작 좌표
    dfs(i, i)


print(len(ans))
ans.sort()
for a in ans:
    print(a)
