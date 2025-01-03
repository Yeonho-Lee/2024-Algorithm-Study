#include <iostream>
#include <queue>
#include <string>
#include <array>
#include <cstring>
using namespace std;
vector<array<int, 2>> graph[1001];
int n,m,x,temp[3];
long long costmax=0, costsum, cost, curr, dis[1001], ncity, ncost;

void dijkstra(int start){
    priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> q;
    q.push({0, start});
    for(int i=0;i<1001;i++) dis[i]=2100000000;
    dis[start]=0;
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        cin >> temp[0] >> temp[1] >> temp[2];
        graph[temp[0]].push_back({temp[1], temp[2]}); // [0]번 마을로 [1]만큼의 cost 필요
    }
    for(int i=1;i<=n;i++){
        costsum=0;
        dijkstra(i);
        costsum+=dis[x];
        dijkstra(x);
        costsum+=dis[i];
        costmax = max(costsum, costmax);
    }
    cout << costmax;
}