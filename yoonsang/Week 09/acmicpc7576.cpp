#include <iostream>
#include <queue>
#include <array>
using namespace std;
int n,m,a[1001][1001],maxday=0,dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
queue<array<int,3>> q; // x, y, day
vector<array<int,2>> v;
void bfs(){
    for(auto i:v) q.push({i[0],i[1],0});
    while(!q.empty()){
        int x=q.front()[0], y=q.front()[1], day=q.front()[2];
        for(int i=0;i<4;i++) {
            int nx = x+dx[i], ny=y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && a[ny][nx]==0) {
                q.push({nx, ny, day+1}); a[ny][nx]=1;
            }
        }
        maxday = max(maxday, day);
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; // x가 n, y가 m
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) { 
        cin >> a[i][j];
        if(a[i][j]==1) v.push_back({j,i}); // x, y 넣음
    }
    bfs();
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) { 
        if(a[i][j]==0) { cout << -1; return 0; }
    }
    cout << maxday; return 0;
}