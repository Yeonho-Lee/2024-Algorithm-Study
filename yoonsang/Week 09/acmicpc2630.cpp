#include <iostream>
#include <queue>
#include <array>
#include <cmath>
using namespace std;
queue<array<int, 3>> q; // x, y, n
int n, N, a[129][130]={}, color[2] = {0,0};
bool check(int b[]){ 
    int color = a[b[0]][b[1]];
    for(int i=b[0];i<=b[2];i++) {
        for(int j=b[1];j<=b[3];j++) {
            if(a[i][j]!=color) return false;
        }
    }
    return true;
}// true: 색이 같다, false: 색이 다르다
void ma(int n){
    q.push({1, 1, n});
    while(!q.empty()){
        if(n==1) {
            color[a[q.front()[0]][q.front()[1]]]++;
            q.pop();
            continue;
        }
        int c[4]={q.front()[0], q.front()[1], q.front()[0]+q.front()[2]-1, q.front()[1]+q.front()[2]-1};
        if(check(c)) {
            color[a[q.front()[0]][q.front()[1]]]++;
            q.pop();
        } else {
            q.push({q.front()[0], q.front()[1], q.front()[2]/2});
            q.push({q.front()[0]+q.front()[2]/2, q.front()[1], q.front()[2]/2});
            q.push({q.front()[0], q.front()[1]+q.front()[2]/2, q.front()[2]/2});
            q.push({q.front()[0]+q.front()[2]/2, q.front()[1]+q.front()[2]/2, q.front()[2]/2});
            q.pop();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){ for(int j=1;j<=n;j++) { cin >> a[i][j]; }}
    ma(n);
    cout << color[0] << '\n' << color[1];
}