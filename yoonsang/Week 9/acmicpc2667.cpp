#include <iostream>
#include <string>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;
int n,a[26][27]={},b[1000]={},cnt=0,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool visited[26][27]={};
string s;
queue<array<int, 2>> q; // x, y
void ab(int y, int x){
    int size=1;
    q.push({x, y});
    visited[y][x]=true;
    while(!q.empty()){
        for(int i=0;i<4;i++){
            int nx=q.front()[0]+dx[i], ny=q.front()[1]+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && a[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({nx, ny});
                size++;
            }
        }
        q.pop();
    }
    b[cnt]=size;
    cnt++;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<n;j++){
            a[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!visited[i][j] && a[i][j]) ab(i, j);
        }
    }
    sort(b, b+cnt);
    cout << cnt << '\n';
    for(int i=0;i<cnt;i++) cout << b[i] << '\n';
}