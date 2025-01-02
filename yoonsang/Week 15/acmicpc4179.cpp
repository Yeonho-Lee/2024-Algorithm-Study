#include <iostream>
#include <queue>
#include <string>
#include <array>
using namespace std;
queue<array<int, 4>> q; // r, c, type: 0=지훈, 1=불, time
int r, c, start[2], times=0, d[4][2]={{0,1},{0,-1},{1,0},{-1,0}}, typetrack=1;
string map[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++) cin >> map[i];

    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        if(map[i][j]=='J') {start[0] = i; start[1] = j;}
        if(map[i][j]=='F') q.push({i, j, 1, 0});
    }

    if(start[0]==0 || start[0]==r-1 || start[1]==0 || start[1]==c-1) { cout << "1"; return 0;}
    q.push({start[0], start[1], 0, 0});
    
    while(!q.empty()){
        for(int i=0;i<4;i++){
            int nx=q.front()[0]+d[i][0], ny=q.front()[1]+d[i][1];
            bool flg = q.front()[2];
            if(0<=nx && nx<r && 0<=ny && ny<c && map[nx][ny]!='#' && map[nx][ny]!='F'){
                if(flg) { // 불이 퍼질 때
                    map[nx][ny]='F';
                    q.push({nx, ny, 1, q.front()[3]+1});
                } else { // 지훈이 이동할 때
                    if(map[nx][ny]=='J') continue;
                    map[nx][ny]='J';
                    if(nx==0 || nx==r-1 || ny==0 || ny==c-1) { cout << q.front()[3]+2; return 0; }
                    q.push({nx, ny, 0, q.front()[3]+1});
                }
            }
        }
        q.pop();
    }
    cout << "IMPOSSIBLE";
}