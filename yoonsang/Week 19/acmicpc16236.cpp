#include <iostream>
#include <queue>
#include <array>
using namespace std;
queue<array<int, 3>> q;
int n, a[20][20]={}, marking[20][20]={}, marks=1, initdis, tot=0;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}},r,c,dis,nr,nc;
bool visited[20][20]={},flg;

struct Shark{
    int size=2, r, c, eaten=0;
};

// 개큰 스파게티 코드

int main(){
    cin >> n;
    Shark shark;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        cin >> a[i][j];
        if(a[i][j]==9) {shark.r=i; shark.c=j;}
    }
    while(1){
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            visited[i][j]=false; marking[i][j]=0;
        }
        marks=0;
        q.push({shark.r, shark.c, 0});
        visited[shark.r][shark.c]=true;
        flg=false;
        while(!q.empty()){
            r=q.front()[0]; c=q.front()[1]; dis=q.front()[2]; q.pop();
            //cout << r << ' ' << c << ' ' << a[r][c] << '\n';
            if(!flg && a[r][c]!=0 && a[r][c]<shark.size) { flg=true; initdis=dis; }
            if(flg && dis==initdis && a[r][c]!=0 && a[r][c]<shark.size) {
                marking[r][c]=1; continue;
            }
            for(int i=0;i<4;i++) {
                nr=r+d[i][0]; nc=c+d[i][1];
                if(0<=nr && nr<n && 0<=nc && nc<n && !visited[nr][nc] && a[nr][nc]<=shark.size) {
                    visited[nr][nc]=true;
                    q.push({nr, nc, dis+1});
                }
            }
        }
        for(int i=0;i<n;i++) { 
            for(int j=0;j<n;j++) {
                if(marking[i][j]) {
                    //cout << "marking! " << i << ' ' << j << '\n';
                    marks++;
                    a[i][j]=999;
                    a[shark.r][shark.c]=0;
                    tot+=initdis;

                    shark.r=i; shark.c=j;
                    shark.eaten++;
                    if(shark.eaten==shark.size) {
                        shark.eaten=0; shark.size++;
                    }

                    break;
                }
            }
            if(marks) break;
        }
        if(!marks) { cout << tot; return 0; }
        // bfs 돌려서 자기 크기보다 작은거 찾기
        // 처음 발견하면? 해당 위치 별도 맵에 마킹
        // 이후로는 길이 같은거까지만 해당 위치 별도 맵에 마킹
        // 마킹 후 처음부터 돌려서 제일 왼쪽 위에 있는거에 감(숫자만 올려둬)
        // 반복
        // 마킹 수가 0이 될 때까지 반복
    }
}