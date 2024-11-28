#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <cstring>
using namespace std;
int n,m,start,temp[3],dis[20001],cost,now,ncost,nnext;
vector<array<int,2>> graph[20001];
void dijkstra(int node){
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({0, node});
    while(!q.empty()){
        cost = q.top()[0], now=q.top()[1];
        q.pop();
        if(cost>dis[now]) continue;
        for(auto i:graph[now]){
            nnext=i[0], ncost=dis[now]+i[1];
            if(ncost<dis[nnext]) {
                dis[nnext]=ncost;
                q.push({ncost, nnext});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0;i<=20000;i++) dis[i]=199991;
    cin >> n >> m >> start;
    for(int i=0;i<m;i++) {
        for(int j=0;j<3;j++) cin >> temp[j];
        graph[temp[0]].push_back({temp[1],temp[2]}); // next, cost
    }
    dis[start]=0;
    dijkstra(start);
    for(int i=1;i<=n;i++){
        if(dis[i]==199991) cout << "INF\n";
        else cout << dis[i] << '\n';
    }
}