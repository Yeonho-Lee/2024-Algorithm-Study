#include <iostream>
#include <queue>
#include <array>
using namespace std;
int n,m,h,a[100][100][101],maxday=0,dx[6]={-1,1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,-1,1};
queue<array<int,4>> q; // x, y, z, day
vector<array<int,3>> v;
void bfs(){
    for(auto i:v) q.push({i[0],i[1],i[2], 0});
    while(!q.empty()){
        int x=q.front()[0], y=q.front()[1], z=q.front()[2], day=q.front()[3];
        for(int i=0;i<6;i++) {
            int nx = x+dx[i], ny=y+dy[i], nz=z+dz[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h && a[nz][ny][nx]==0) {
                q.push({nx, ny, nz, day+1}); a[nz][ny][nx]=1;
            }
        }
        maxday = max(maxday, day);
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> h; // x가 n, y가 m, z가 h
    for(int k=0;k<h;k++) for(int i=0;i<m;i++) for(int j=0;j<n;j++) { 
        cin >> a[k][i][j];
        if(a[k][i][j]==1) v.push_back({j,i,k}); // x, y, z 넣음
    }
    bfs();
    for(int k=0;k<h;k++) for(int i=0;i<m;i++) for(int j=0;j<n;j++) { 
        if(a[k][i][j]==0) { cout << -1; return 0; }
    }
    cout << maxday; return 0;
}