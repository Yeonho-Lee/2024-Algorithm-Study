import sys
from itertools import combinations

#input data (N <= 50, K <= 26, 자연수, K = 0 가능)
N, K = map(int, sys.stdin.readline().split())

#anta, tica에 있는 5개 알파벳보다 K가 작으면 읽을 수 있는 단어 개수 = 0
if K< 5:
    print(0)
    sys.exit(0)
#K가 26이면 모든 알파벳을 포함하므로 N개의 단어 모두 읽을 수 있음
elif K == 26:
    print(N)
    sys.exit(0)

#알파벳의 순서나 개수와 상관없이 단어에 들어있는 알파벳의 종류만 알면 되므로 set 사용
words = [set(sys.stdin.readline().strip()) for _ in range(N)]

required = set(['a', 'c', 'i', 'n', 't'])       #anta, tica에 있는 알파벳 5개는 필수
unique_set = set()
unique_list = []
max_learn = 0

for i in range(N):
    unique_list.append(words[i] - required)     #리스트에 N개의 단어에서 required에 있는 알파벳을 빼서 추가 (len = N)
    unique_set.update(words[i] - required)      #집합에 N개의 단어에서 required에 있는 알파벳을 빼서 추가 (len <= N)

#len(unique_set) > K-5인 set에 대해 combinations을 쓰면 공집합 생성됨
if len(unique_set) <= K-5:      #unique_set의 원소 개수가 K-5보다 작으면 모든 단어 읽을 수 있음
        print(N)
        sys.exit(0)

#배울 수 있는 알파벳 개수 K개 중에 필수 5개 제외하고 추가로 배울 수 있는 K-5개의 조합 선정
for c in combinations(unique_set, K-5):
    learn_set = set(c)       #unique_list에 있는 집합과 비교하기 위해 set으로 변경
    temp = 0                 #learn_set 조합으로 배울 수 있는 단어 개수 저장
    for unique_word in unique_list:      #각 단어별 존재하는 a,c,i,n,t 제외한 알파벳들에 대해서
        if unique_word <= learn_set:     #learn_set 조합이 unique_word를 포함하면 단어를 배울 수 있음(부분집합)
            temp += 1
    max_learn = max(max_learn, temp)        #기존 max_learn과 비교하여 가장 많이 배울 수 있는 단어 개수 저장

print(max_learn)