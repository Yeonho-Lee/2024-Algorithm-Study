#include <iostream>
#include <queue>
#include <array>
#include <vector>
using namespace std;
void space(int i, int j, bool a[][51]){
    int dx[5] = {-1, 1, 0, 0}, dy[5] = {0, 0, -1, 1};
    queue<array<int, 2>> q;
    q.push({i, j});
    while(!q.empty()) {
        for(int i=0;i<4;i++) {
            int x = q.front()[0]+dx[i], y=q.front()[1]+dy[i];
            if(0 <= x && x <= 50 && 0 <= y && y <= 50 && a[x][y]){ 
                q.push({x, y}); a[x][y]=false;
            }
        }
        q.pop();
    }
}
int main(){
    int t,n,m,num,tempx,tempy;
    cin >> t;
    while(t--) {
        int cnt=0;
        cin >> n >> m >> num;
        bool a[51][51]={};
        while(num--) {
            cin >> tempx >> tempy;
            a[tempx][tempy]=true;
        }
        for(int i=0;i<n;i++) { for(int j=0;j<m;j++) {
            if(a[i][j]) { space(i, j, a); cnt++; }
        }}
        cout << cnt << '\n'; 
    }
}

// 뭔가 조금 더 깔끔하게 짤 수 있을 것 같은데...