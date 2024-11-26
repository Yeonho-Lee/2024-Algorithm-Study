#include <iostream>
#include <string>
#include <queue>
#include <array>
using namespace std;
int n,m,a[100][101]={},dx[4]={-1,1,0,0},dy[4]={0,0,-1,1}, minimum=9999999;
bool visited[100][101]={};
string s;
queue<array<int, 3>> q; // x, y, dis
int bfs(){
    q.push({0,0,1});
    visited[0][0]=true;
    while(!q.empty()){
        for(int i=0;i<4;i++){
            int nx=q.front()[0]+dx[i], ny=q.front()[1]+dy[i];
            if(nx == m-1 && ny == n-1) { minimum = min(minimum, q.front()[2]+1); continue; }
            if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[ny][nx] && a[ny][nx]){
                visited[ny][nx]=true;
                q.push({nx, ny, q.front()[2]+1});
            }
        }
        q.pop();
    }
    return minimum;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    cout << bfs();
}