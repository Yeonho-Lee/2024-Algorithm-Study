(2024-11-08)
C++ 참조자: 변수의 새로운 이름!

int &p = a;
는 a의 별명이 p라는 것과 동일함(동일 변수 이름 두 개)
p 바꿔도 a 바뀜.
** 주의점: 레퍼런스 선언과 동시에 누구를 별명으로 할 지 반드시 지정해야함

레퍼런스(참조자) 좋은 점: 함수에서 포인터로 머리 쥐어뜯을 필요 없이 편하게 사용 가능함!
But, 몇 가지 상황 확인하기
int funcv(int &p) { ~~~ return p; } ==> p가 정상적으로 return됨
int funcv(int &p) { int a; ~~~ return a; } ==> Segfault 오류 발생!
ㄴ a는 return과 함께 사라지는 값인데 그 값 가져오려 하니까 문제 생기지

(2024-11-12)
std::cin, cout, endl는 (엄청 많이) 느리다
cin, cout는 ios_base::sync_with_stdio(0); cin.tie(0);를 앞에 붙여 printf, scanf와의 연결 끊어주고
endl는 endl 대신 '\n'을 사용할 것 <<<<< 얘가 진짜 느림

자료구조 정리
 - stack: Last In First Out
   ㄴ push, pop, top, empty, size 등

 - queue: First In First Out
   ㄴ push, pop, front, back, empty 등

 - vector: 속도 느리지만 메모리 효율 좋은 array
   ㄴ push_back, pop_back, insert, emplace, emplace_back, erase, clear, resize 등
   - 뒤로 데이터 넣는건 O(1)이고 deque에 비해 탐색 성능이 아주 좋음. 그러나 메모리 운용이 조금 비효율적이고 맨 뒤로 데이터 넣는게 아닐 경우 O(n)의 시간이 걸림(느림)

 - map: python의 dict와 비슷하고 빠른 자료구조
   ㄴ insert, find, erase, size, clear, empty 등

 - deque: 양쪽으로 입출력 가능한 큐
   ㄴ push_front, push_back, pop_front(), pop_back(), front, back 등
   - vector와 비슷하지만 앞,뒤로 O(1)이고 탐색 성능은 좋지 못하지만 메모리 운용이 효율적임. 중간에 넣는건 vector와 같이 O(n)의 시간 걸림

 - list: 앞뒤 삽입/삭제 빠른데 인덱스 검색 안되는 자료구조
   ㄴ 그닥 쓸모 없을듯

 - set: python이랑 같은데 순서 정렬돼있음 그리고 빠름(map과 같음)

 - unordered_set: 탐색 빠른 set
  ㄴ 해시 기반으로 데이터 저장해 탐색 O(1) (평균)
  ㄴ 정렬 지원 안 하지만 값의 유무 확인이 빠름
  ㄴ 얘가 python set이랑 똑같이 동작할지도

 - multiset, unordered_multiset: 중복 허용하는 set

 - unordered_map: 해시 기반 map

 - priority_queue: 우선순위 큐
   ㄴ Max Heap 형태로 저장하는 큐

 - bitset: 비트 다루는거(나중에 배우자)



for문의 새로운 사용법: python식
 - for(auto i: v)는 v.size()만큼 반복 작동하며 *i로 v 안의 내용에 접근 가능