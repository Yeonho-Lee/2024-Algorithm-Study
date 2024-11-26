#include <iostream>
#include <string>
#include <queue>
#include <array>
using namespace std;
int n,m,a[600][601],init[2],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},cnt=0; // n행 m열
string temp;
queue<array<int, 2>> q;
void bfs(){
    q.push({init[0], init[1]}); // x, y: y행 x열
    while(!q.empty()){
        for(int i=0;i<4;i++){
            int nx = q.front()[0]+dx[i], ny = q.front()[1]+dy[i];
            if(0 <= nx && nx < m && 0 <= ny && ny < n && a[ny][nx]!=9999999) {
                q.push({nx, ny});
                if(a[ny][nx]==1) cnt++;
                a[ny][nx]=9999999;
            }
        }
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> temp;
        for(int j=0;j<m;j++) {
            if(temp[j]=='O') a[i][j]=0;
            else if(temp[j]=='P') a[i][j]=1;
            else if(temp[j]=='X') a[i][j]=9999999;
            else if(temp[j]=='I') {
                a[i][j] = 9999999;
                init[0] = j;
                init[1] = i;
            }
        }
    }
    bfs();
    if(cnt) cout << cnt;
    else cout << "TT";
}

// x, y 처리가 너무 좀 이상한데