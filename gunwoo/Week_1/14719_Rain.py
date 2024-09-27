import sys

#input data
row, col = map(int, sys.stdin.readline().split())
blocks = list(map(int, sys.stdin.readline().split()))

#빗물의 양 변수 지정
rain = 0

for i in range(1, len(blocks)):
    left_max = max(blocks[:i])          #왼쪽에서 i-1번째 중에 가장 높은 기둥
    right_max = max(blocks[i:])         #i번째부터 오른쪽 방향으로 가장 높은 기둥
    lower = min(left_max, right_max)    #둘 중 낮은 기둥

    if blocks[i] < lower:               #각 위치별 담기는 빗물의 양 계산
        rain += lower - blocks[i]
    

print(rain)