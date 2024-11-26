import sys
import math

n = int(sys.stdin.readline())
a = []
for i in range(n): a.append(list(map(int, sys.stdin.readline().split())))
b = []
b.insert(0, [a[0][0], a[0][1]])
for i in range(1, n):
    check = int(len(b)/2)
    left = 0
    right = len(b)
    while(1):
        ## check의 최댓값은 right-1인데 검사 중인 데이터의 값이 배열 내의 값 중 가장 큰 경우
        ## insert의 위치가 right(=check+1)이어야 하기 때문에 여기서 확인
        if right-left <= 1:
            if b[check][1] < a[i][1]: b.insert(check+1, [a[i][0], a[i][1]])
            elif b[check][1] > a[i][1]: b.insert(check, [a[i][0], a[i][1]])
            elif b[check][0] < a[i][0]: b.insert(check+1, [a[i][0], a[i][1]])
            else: b.insert(check, [a[i][0], a[i][1]])
            break
        if b[check][1] < a[i][1]: 
            left = check
            check = int((right+check)/2)
        elif b[check][1] > a[i][1]: 
            right = check
            check = int((left+check)/2)
        elif b[check][0] < a[i][0]: 
            left = check
            check = int((right+check)/2)
        else: 
            right = check
            check = int((left+check)/2)
for i in range(n):
    print(b[i][0], b[i][1])