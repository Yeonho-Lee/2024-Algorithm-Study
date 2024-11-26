#include <iostream>
#include <string.h>
using namespace std;
bool visited[102]={}, a[102][102]={};
int n,k,temp1, temp2, cnt=0;
void dfs(int node){
    cnt++;
    visited[node] = true;
    for(int i=1;i<=n;i++) {
        if(a[node][i] && !visited[i]) dfs(i);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    for(int i=1;i<=k;i++) {
        cin >> temp1 >> temp2;
        a[temp1][temp2] = true;
        a[temp2][temp1] = true;
    }
    dfs(1);
    cout << cnt-1;
}