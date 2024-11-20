#include <iostream>
#include <queue>
#include <array>
using namespace std;
queue<array<int, 2>> q;
int n,k,a[100001]={};
int bfs(int n, int k) {
    q.push({n, 0});
    int minimum=99999;
    while(!q.empty()){
        int p = q.front()[0], pp=q.front()[1];
        if(p==k) {
            minimum = min(minimum, pp%100000);
            q.pop();
            continue;
        }
        if(p!=0 && (a[p-1]==0 || pp+1<a[p-1]%100000)) { q.push({p-1, pp+1}); a[p-1]=pp+1+100000; }
        if(p!=100000 && (a[p+1]==0 || pp+1<a[p+1]%100000)) { q.push({p+1, pp+1}); a[p+1]=pp+1+100000; }
        if(p<=50000 && (a[2*p]==0 || pp<a[2*p]%100000)) { q.push({2*p, pp}); a[2*p]=pp+100000; }
        q.pop();
    }
    a[n]=0;
    return minimum;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(n==k) {cout << '0'; return 0;}
    if(n>k) {cout << n-k; return 0;}
    cout << bfs(n, k);
}