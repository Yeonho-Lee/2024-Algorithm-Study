#include <iostream>
#include <string>
#include <queue>
#include <array>
using namespace std;
queue<array<int, 4>> q;
string s[1000];
int n,m,r,c,broke,t,nr,nc,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool visited[2][1000][1000]={};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> s[i];
    q.push({0, 0, 0, 0}); // r, c, broke, time
    while(!q.empty()){
        r=q.front()[0]; c=q.front()[1]; broke=q.front()[2]; t=q.front()[3];
        q.pop();
        if(r==n-1 && c==m-1) { cout << t+1; return 0;}
        for(int i=0;i<4;i++){
            nr=r+d[i][0]; nc=c+d[i][1];
            if(0<=nr && nr<n && 0<=nc && nc<m) {
                if(s[nr][nc]=='1' && broke==0 && !visited[1][nr][nc]) {
                    visited[1][nr][nc]=true;
                    q.push({nr, nc, 1, t+1});
                } else if (s[nr][nc]=='0') { // 벽이 없을 때
                    if(broke==0 && !visited[0][nr][nc]) {
                        visited[0][nr][nc]=true;
                        q.push({nr, nc, 0, t+1});
                    } else if(broke==1 && visited[1][nr][nc]==false) {
                        visited[1][nr][nc]=true;
                        q.push({nr, nc, 1, t+1});
                    }
                }
            }
        }
    }
    cout << -1;
}