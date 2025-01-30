#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> q;
vector<int> viruses;
int n,m,a[9][9],d[4][2]={{0,1},{0,-1},{-1,0},{1,0}},h,w,nh,nw,maximum=0,cnt;
bool visited[9][9]={};

void t(int depth, int prevs){
    if(depth==3) {
        for(int i=0;i<81;i++) visited[i/9][i%9]=false;
        for(auto i:viruses) q.push(i);
        while(!q.empty()){
            h=q.front()/m; w=q.front()%m;
            for(int i=0;i<4;i++){
                nh=h+d[i][0], nw=w+d[i][1];
                if(0<=nh && nh<n && 0<=nw && nw<m && !visited[nh][nw] && a[nh][nw]==0){
                    q.push(nh*m+nw);
                    visited[nh][nw]=true;
                }
            }
            q.pop();
        }
        cnt=0;
        for(int i=0;i<n*m;i++) {
            if(!visited[i/m][i%m] && a[i/m][i%m]==0) cnt++;
        }
        maximum=max(maximum,cnt);
        return;
    }

    for(int i=prevs;i<n*m;i++){
        if(a[i/m][i%m]!=0) continue;
        a[i/m][i%m]=1;
        t(depth+1, i+1);
        a[i/m][i%m]=0;
    }
}

int main(){
    cin >> n >> m; 
    for(int i=0;i<n*m;i++) {
        cin >> a[i/m][i%m];
        if(a[i/m][i%m]==2) viruses.push_back(i);
    }
    t(0, 0);
    cout << maximum;
}