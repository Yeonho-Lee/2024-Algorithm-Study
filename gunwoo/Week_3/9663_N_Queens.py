import sys

N = int(sys.stdin.readline())
row = [0] * N       # row[i] = j 라면 (i, j)에 queen 존재
count = 0

def possible(x):
    for r in range(x):
        if row[r] == row[x] or abs(row[r] - row[x]) == abs(r - x):
            return False

    return True

def dfs(num_q):
    global count
    if num_q == N:
        count += 1
        return
    
    for i in range(N):
        row[num_q] = i      # num_q행 i열
        if possible(num_q):
            dfs(num_q + 1)

dfs(0)
print(count)