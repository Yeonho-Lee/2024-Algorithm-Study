#include <iostream>
#include <queue>
#include <array>
using namespace std;
queue<array<int, 2>> q;
int n,m,r,c,a[100][100]={},v[100][100]={},d[4][2]={{0,1},{0,-1},{1,0},{-1,0}},nr,nc;
bool visited[100][100],flg;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
    for(int t=0;;t++){
        while(!q.empty()) q.pop();
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) { v[i][j]=0; visited[i][j]=false; }
        for(int i=0;i<n;i++) {
            q.push({i, 0});
            q.push({i, m-1});
        }
        for(int i=1;i<m-1;i++) {
            q.push({0, i});
            q.push({0, n-1});
        }
        while(!q.empty()) {
            r=q.front()[0]; c=q.front()[1]; q.pop();
            for(int i=0;i<4;i++) {
                nr=r+d[i][0]; nc=c+d[i][1];
                if(0<=nr && nr<n && 0<=nc && nc<m) {
                    if(a[nr][nc]==0 & !visited[nr][nc]) {
                        q.push({nr, nc});
                        visited[nr][nc]=true;
                    } else {
                        v[nr][nc]++;
                    }
                }
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
            if(v[i][j]>=2) a[i][j]=0;
        }
        flg=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]) {flg=true; break;}
            }
            if(flg) break;
        }
        if(!flg) {cout << t+1; return 0;}
    }
}