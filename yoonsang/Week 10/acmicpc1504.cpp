#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <cstring>
using namespace std;
int n,e,temp[3],mid[2],dis[801],cost,curr,ncity,ncost;
long long sum[6];
vector<array<int, 2>> graph[801];
void shortest(int init){ // type=0: 안지남, type=1: 지남
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({0, init});
    while(!q.empty()){
        cost=q.top()[0], curr=q.top()[1];
        q.pop();
        if(cost>dis[curr]) continue;
        for(int i=0;i<graph[curr].size();i++) {
            ncity=graph[curr][i][0], ncost=dis[curr]+graph[curr][i][1];
            if(ncost<dis[ncity]) {
                dis[ncity] = ncost;
                q.push({ncost, ncity});
            }
        }

    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> temp[0] >> temp[1] >> temp[2];
        graph[temp[0]].push_back({temp[1], temp[2]});
        graph[temp[1]].push_back({temp[0], temp[2]});
    }
    cin >> mid[0] >> mid[1];
    int dest[3][3]={{1,mid[0],mid[1]},{mid[0],mid[1],n},{mid[1],mid[0],n}};
    for(int i=0;i<3;i++){
        for(int i=1;i<=800;i++) dis[i]=2100000001;
        dis[dest[i][0]]=0;
        shortest(dest[i][0]);
        sum[2*i]=dis[dest[i][1]];
        sum[2*i+1]=dis[dest[i][2]];
    }
    long long tempsum=sum[0]+sum[2]+sum[5];
    if(tempsum>sum[1]+sum[4]+sum[3]) tempsum=sum[1]+sum[4]+sum[3];
    if(tempsum>2100000000) cout << -1;
    else cout << tempsum;
}

// sum이 int일 때
// tempsum=sum[0]+sum[2]+sum[5];는 sum[0], sum[2], sum[5]를 먼저 int에서 더하고 long long으로 바꾸기 때문에 overflow 가능성 존재함
// 신기한거 하나 알아가네요.....