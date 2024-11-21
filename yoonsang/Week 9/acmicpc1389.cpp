#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <malloc.h>
using namespace std;
vector<int> graph[101];
int n,m,temp,temp1,minimum;
int bfs(int node){
    int cnt=0,a[102]={};
    queue<array<int,2>> q;
    q.push({node,0});
    while(!q.empty()){
        for(auto i:graph[q.front()[0]]) {
            if(a[i]==0) {
                q.push({i,q.front()[1]+1});
                a[i]=q.front()[1]+1;
            }
        }
        q.pop();
    }
    for(int i=1;i<=n;i++) cnt+=a[i];
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> temp >> temp1;
        graph[temp].push_back(temp1);
        graph[temp1].push_back(temp);
    }
    int minimum=99999999, m;
    for(int i=1;i<=n;i++) { 
        int k = bfs(i);
        if(minimum>k) { minimum=k; m=i; }
    }
    cout << m;
}
// bfs가 return할 때 케빈 베이컨의 수보다 2 큰 수가 return되지만 모든 인원에 대해 2가 더해지므로 프로그램 실행 상 오류 없음