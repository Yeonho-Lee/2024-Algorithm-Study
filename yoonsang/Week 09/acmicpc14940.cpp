#include <iostream>
#include <string>
#include <queue>
#include <array>
#include <algorithm>
#include <malloc.h>
using namespace std;
int n,m,init[2],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int a[1000][1001];
bool visited[1000][1001]={};
string s;
queue<array<int, 3>> q; // x, y, dis
void bfs(){
    q.push({init[1], init[0], 0});
    visited[init[0]][init[1]] = true;
    a[init[0]][init[1]] = 0;
    while(!q.empty()){
        for(int i=0;i<4;i++) {
            int nx=q.front()[0]+dx[i], ny=q.front()[1]+dy[i];
            if(0 <= nx && nx < m && 0 <= ny && ny < n) {
                if(!visited[ny][nx] && a[ny][nx]==-1) {
                visited[ny][nx]=true;
                a[ny][nx]=q.front()[2]+1;
                q.push({nx, ny, q.front()[2]+1});
            }
            }
        }
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]==1) a[i][j]=-1;
            if(a[i][j]==2) { init[0]=i; init[1]=j; }
        }
    }
    bfs();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}