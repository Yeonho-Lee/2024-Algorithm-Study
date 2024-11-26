#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[9], stored[9]={};
bool visited[9]={};
void backtracking(int d){
    if(d==m) {
        for(int i=0;i<m;i++) cout << stored[i] << ' ';
        cout << '\n';
        return;
    }
    int prevused = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && prevused!=a[i]){
            visited[i]=true;
            stored[d]=a[i];
            prevused=a[i];
            backtracking(d+1);
            visited[i]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    backtracking(0);
}