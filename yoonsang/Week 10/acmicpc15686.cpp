#include <iostream>
#include <cmath>
using namespace std;
int n,m, temp, sum=1000000, home[101][2]={}, dis[101][14]={}, chicken[14][2]={}, homecnt=0, chickencnt=0, a[14]={};
// home: i번째 집의 위치(k), dis: i번째 집의 j번째 치킨집과의 거리, chicken: i번째 치킨집의 위치(k)
bool visited[14]={};
void backtracking(int d){
    if(d==m) {
        int tempsum=0;
        // a[i]: 페업하지 않을 치킨집의 번호, d까지
        for(int i=0;i<homecnt;i++) {
            int tempmin=99999;
            for(int j=0;j<d;j++) {
                tempmin = min(tempmin, dis[i][a[j]]);
            }
            tempsum+=tempmin;
        }
        sum=min(tempsum, sum);
    }
    for(int i=d;i<chickencnt;i++) {
        if(visited[i]) continue;
        visited[i]=true;
        a[d]=i;
        backtracking(d+1);
        visited[i]=false;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> temp;
            if(temp==1) { home[homecnt][0]=j; home[homecnt][1]=i; homecnt++; }
            if(temp==2) { chicken[chickencnt][0]=j; chicken[chickencnt][1]=i; chickencnt++; }
        }
    }
    for(int i=0;i<homecnt;i++) {
        for(int j=0;j<chickencnt;j++) {
            dis[i][j] = abs(home[i][0]-chicken[j][0])+abs(home[i][1]-chicken[j][1]);
        }
    }
    backtracking(0);
    cout << sum;
}
//