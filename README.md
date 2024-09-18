# 2024-Algorithm-Study

> 코딩 테스트 준비를 위한 스터디입니다.

-   기간: 2024년 3월~
-   정기 회의: ?
-   참고 사이트: [프로그래머스](https://programmers.co.kr/learn/challenges), [백준](https://www.acmicpc.net/)
-   언어: Java, C++

## 스터디 규칙

#### 문제 풀이

1. 주마다 회의 시간에는 각자 1문제 풀이 설명.
    1. 개념+알고리즘+풀이 방식 자세하게 설명하기.
    2. 만약 상대가 이해 못하면 이해할 때까지 설명해야 함.
2. 깃허브 활용해서 Pull Request로 코드 리뷰 진행함.
    1. 서로에 대한 코드 리뷰는 토요일까지 완료하기.
    2. 반드시 코드 리뷰 후에 main branch로 merge.
    3. 기본적으로 올릴 때는 각자 이름으로 된 branch에 올림.
3. 코드 리뷰 받은 것에 대해서는 다음 회의 전까지 수정해서 다시 깃허브에 올리기.

#### 설명 방식

1. 적용 알고리즘 개념 간단하게 설명하기
2. 문제 풀이를 위한 접근 방식(or 개념) 설명
3. 기본 코드에 대한 설명
4. 추가적으로 개선한 코드에 대한 설명
5. 시간 복잡도, 공간 복잡도 계산 => 어려우면 실행 시간 캡처로 대체
6. 사용 라이브러리 정리
7. 기타(문제 풀이에 어려웠던 점, 구현하고자 했는데 실패한 방식)

#### 진행 방식

-   만약 주차에 해당하는 문제 풀이가 미완료 시, 회의 당일에 직접 문제 풀이 진행해야 함.
-   끝날 때까지 회의는 끝나지 않음..(열심히 하자..다른 사람을 생각하며)

## 깃 이용 방식
#### 최초 세팅 - 아이디와 이메일
```
$ git config --global user.name "깃허브아이디"
$ git config --global user.email "이메일"
```
#### 최초 세팅 - 깃 클론하기
```
// 보내드린 링크 가서 복사 해오면 -> 저장하고 싶은 위치에서 터미널에 입력
$ git clone https://github.com/아이디/저장소이름.git
```
#### 깃 브랜치 만들기
```
$ git branch (브랜치 이름) // local branch 만들기
$ git switch (브랜치 이름) // 작업 중인 branch 바꾸기
```

#### 깃 작업하기
```
$ git pull
// 작업하기 전에 해줘야 함

$ git add .
// 작업한 것들을 모두 staging area로 올림
$ git commit -m "커밋 메세지"
$ git push // 안되면 $ git push -u origin/(브랜치 이름)
// 커밋한 것들을 repository에 반영시
```

이후에 github 들어가서 pull request 생성하기! -> 주차별로 한번씩
comment 받은 후에 squash merge

## 파일 및 폴더 구조

#### 프로그래머스

#### 백준

## 일정표

#### 1차 : 코딩테스트 고득점 Kit (프로그래머스)

| **주차** | **폴더명**          | **문제 1**                                                               | **문제 2**                                                                  | **문제 3**                                                                 | **진행 현황** |
| -------- | ------------------- | ------------------------------------------------------------------------ | --------------------------------------------------------------------------- | -------------------------------------------------------------------------- | ------------- |
| 1주차    | greedy              | [조이스틱](https://programmers.co.kr/learn/courses/30/lessons/42860)     | [큰 수 만들기](https://programmers.co.kr/learn/courses/30/lessons/42883)    |                                                                            | `진행 완료`   |
| 2주차    | brute_force         | [소수 찾기](https://programmers.co.kr/learn/courses/30/lessons/42839)    | [카펫](https://programmers.co.kr/learn/courses/30/lessons/42842)            |                                                                            | `진행 완료`   |
| 3주차    | stack_queue         | [주식가격](https://programmers.co.kr/learn/courses/30/lessons/42584)     | [프린터](https://programmers.co.kr/learn/courses/30/lessons/42587)          |                                                                            | `진행 완료`   |
| 4주차    | dfs_bfs             | [네트워크](https://programmers.co.kr/learn/courses/30/lessons/43162)     | [단어 변환](https://programmers.co.kr/learn/courses/30/lessons/43163)       | [타겟 넘버](https://programmers.co.kr/learn/courses/30/lessons/43165)      | `진행 완료`   |
| 5주차    | hash                | [베스트앨범](https://programmers.co.kr/learn/courses/30/lessons/42579)   | [위장](https://programmers.co.kr/learn/courses/30/lessons/42578)            | [전화번호 목록](https://programmers.co.kr/learn/courses/30/lessons/42577)  | `진행 완료`   |
| 6주차    | sort                | [H-Index](https://programmers.co.kr/learn/courses/30/lessons/42747)      | [K번째수](https://programmers.co.kr/learn/courses/30/lessons/42748)         | [가장 큰 수](https://programmers.co.kr/learn/courses/30/lessons/42746)     | `진행 완료`   |
| 7주차    | binary_search       | [입국심사](https://programmers.co.kr/learn/courses/30/lessons/43238)     | [징검다리](https://programmers.co.kr/learn/courses/30/lessons/43236)        |                                                                            | `진행 완료`   |
| 8주차    | dynamic_programming | [N으로 표현](https://programmers.co.kr/learn/courses/30/lessons/42895)   | [등굣길](https://programmers.co.kr/learn/courses/30/lessons/42898)          | [정수 삼각형](https://programmers.co.kr/learn/courses/30/lessons/43105)    | `진행 완료`   |
| 9주차    | heap                | [더 맵게](https://programmers.co.kr/learn/courses/30/lessons/42626)      | [디스크 컨트롤러](https://programmers.co.kr/learn/courses/30/lessons/42627) | [이중우선순위큐](https://programmers.co.kr/learn/courses/30/lessons/42628) | `진행 완료`   |
| 10주차   | graph               | [가장 먼 노드](https://programmers.co.kr/learn/courses/30/lessons/49189) | [방의 개수](https://programmers.co.kr/learn/courses/30/lessons/49190)       | [순위](https://programmers.co.kr/learn/courses/30/lessons/49191)           | `진행 완료`   |
