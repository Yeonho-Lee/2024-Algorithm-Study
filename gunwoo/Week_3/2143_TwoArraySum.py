import sys
from collections import defaultdict

T = int(sys.stdin.readline())
N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
B = list(map(int, sys.stdin.readline().split()))

A_dict = defaultdict(int)
ans = 0

for i in range(len(A)):
    A_sum = 0
    for j in range(i, len(A)):
        A_sum += A[j]
        A_dict[A_sum] += 1

for i in range(len(B)):
    B_sum = 0
    for j in range(i, len(B)):
        B_sum += B[j]
        if (T - B_sum) in A_dict:
            ans += A_dict[T - B_sum]

print(ans)