import sys

#input data (10 <= N < 100,000, 0 < S <= 100,000,000, nums의 원소: 10000이하의 자연수)
N, S = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

#변수 지정
first, second = 0, 0
prefix_sum = nums[0]
min_len = float("inf")      #무한대로 초기값 설정

while True:
    if prefix_sum < S:      #nums의 0번째 원소부터 S보다 커지기 전까지 합을 구함
        first += 1          
        if first == N:      #first N까지 다 도는데도 S보다 큰 값이 안 만들어지면 while문 탈출
            break
        prefix_sum += nums[first]
    #prefix_sum >= S 일 때
    else:
        min_len = min(min_len, first - second + 1)      #기존의 min_len의 값과 새로운 length 중 최소값 계산 
        prefix_sum -= nums[second]      #prefix_sum에서 nums 배열의 값들을 하나씩 뺌
        second += 1

if min_len == float("inf"):     #초기값과 변화가 없으면 0 출력
    print(0)
else:
    print(min_len)