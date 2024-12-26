#include <iostream>
#include <string>
using namespace std;
int n,m,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},maxx=0;
string s[20];
bool visited[27]={};
void dfs(int x, int y, int d){
    maxx=max(maxx,d);
    for(int i=0;i<4;i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if(0<=nx && nx<m && 0<=ny && ny<n && !visited[s[ny][nx]-'A']) {
            visited[s[ny][nx]-'A']=true;
            dfs(nx,ny,d+1);
            visited[s[ny][nx]-'A']=false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> s[i];
    visited[s[0][0]-'A']=true;
    dfs(0, 0, 1);
    cout << maxx;
}