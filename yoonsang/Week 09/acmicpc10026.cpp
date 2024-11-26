#include <iostream>
#include <queue>
#include <array>
#include <string>
using namespace std;
int n, normal[100][101], abnormal[100][101], dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},normalcnt=0,abnormalcnt=0;
string s;
void bfs(int (&arr)[100][101], int i, int j){
    queue<array<int,2>> q;
    int standard = arr[i][j];
    q.push({j,i});
    while(!q.empty()){
        int x=q.front()[0], y=q.front()[1];
        for(int i=0;i<4;i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[ny][nx]==standard) {
                q.push({nx, ny}); arr[ny][nx]=0;
            }
        }
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<n;j++) {
            if(s[j]=='R') { normal[i][j]=1; abnormal[i][j]=1; }
            else if(s[j]=='G') { normal[i][j]=2; abnormal[i][j]=1; }
            else { normal[i][j]=3; abnormal[i][j]=2; }
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(normal[i][j]!=0) { bfs(normal, i, j); normalcnt++; }
        if(abnormal[i][j]!=0) { bfs(abnormal, i, j); abnormalcnt++; }
    }
    cout << normalcnt << ' ' << abnormalcnt;
}