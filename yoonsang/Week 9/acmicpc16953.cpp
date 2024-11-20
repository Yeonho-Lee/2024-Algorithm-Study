#include <iostream>
#include <queue>
#include <array>
using namespace std;
int n, m;
bool lock;
queue<array<long long, 2>> q;
int bfs(){
    q.push({n, 0});
    while(!q.empty()){
        if(q.front()[0]>m) { q.pop(); continue; }
        if(q.front()[0]==m) return q.front()[1]+1;
        q.push({q.front()[0]*2, q.front()[1]+1});
        q.push({q.front()[0]*10+1, q.front()[1]+1});
        q.pop();
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cout << bfs();
}