#include <iostream>
#include <queue>
#include <array>
using namespace std;
queue<array<int, 2>> q;
int n,k,a[100001]={};
int bfs(int n, int k) {
    q.push({n, 0});
    a[n]=1;
    while(!q.empty()){
        int p = q.front()[0];
        if(p==k) return q.front()[1];
        if(p!=0 && a[p-1]==0) { q.push({p-1, q.front()[1]+1}); a[p-1]=1; }
        if(p!=100000 && a[p+1]==0) { q.push({p+1, q.front()[1]+1}); a[p+1]=1; }
        if(p<=50000 && a[2*p]==0) { q.push({2*p, q.front()[1]+1}); a[2*p]=1; }
        q.pop();
    }
    return -1;
} // 뭐야 찾는 중간에는 10만 밖으로 넘어가도 되나
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(n==k) {cout << '0'; return 0;}
    cout << bfs(n, k);
}