#include <iostream>
#include <cmath>
#include <queue>
#include <array>
using namespace std;
int n, temp, sq[226]={0,1,4,},cnt=0;
int find(int n){ // 호출 시마다 10회 연산
    int left=1, right=225, mid;
    for(int i=0;i<ceil(log2(225)+1);i++){
        mid = (left+right)/2;
        if(n<sq[mid]) right = mid;
        else if(n>sq[mid]) left = mid;
        else return mid;
    }
    return mid;
}
void bfs(int n){
    queue<array<int, 3>> q; // 현재 수(temp), 연산 횟수(cnt), 직전 제곱수
    for(int i=1;i<=find(n);i++) { q.push({n, 0, i}); }
    while(!q.empty()) {
        if(q.front()[1]>=cnt || find(q.front()[0])>q.front()[2]) { q.pop(); continue; }
        // 연산 횟수가 cnt에 도달했거나 현재 수의 제곱근이 직전 제곱수보다 크면 return
        int sqrt = find(q.front()[0]);
        for(int i=1;i<=sqrt;i++) {
            if(q.front()[0]-i*i<0) break;
            if(q.front()[0]-i*i==0) { cnt=q.front()[1]+1; break; }
            q.push({q.front()[0]-i*i, q.front()[1]+1, i});
        }
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=3;i<=224;i++) sq[i]=i*i;
    cin >> n;
    temp = n;
    while(temp) { temp-=pow(find(temp),2); cnt++; } // cnt 최댓값 설정
    temp=n;
    bfs(n);
    cout << cnt;
}