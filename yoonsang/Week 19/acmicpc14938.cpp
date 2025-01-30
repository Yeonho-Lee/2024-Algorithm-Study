#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;
vector<array<int, 2>> v[101];
int n,m,r,items[101],temp[3],costs[101],maxitems=0,cost,curr,ncity,ncost,tempitem=0;

int dijkstra(int node){
    tempitem=0;
    fill_n(costs, 101, 99999999);
    costs[node]=0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({0, node});
    while(!q.empty()){
        cost=q.top()[0], curr=q.top()[1];
        q.pop();
        if(cost>costs[curr]) continue;
        for(auto i:v[curr]) {
            ncity=i[1], ncost=costs[curr]+i[0];
            if(ncost<costs[ncity]) {
                costs[ncity] = ncost;
                q.push({ncost, ncity});
            }
        }
    }
    for(int i=1;i<=n;i++) if(costs[i]<=m) tempitem+=items[i];
    return tempitem;
}

int main(){
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++) cin >> items[i];
    for(int i=0;i<r;i++) {
        cin >> temp[0] >> temp[1] >> temp[2];
        v[temp[0]].push_back({temp[2], temp[1]}); // distance, destination
        v[temp[1]].push_back({temp[2], temp[0]});
    }
    for(int i=1;i<=n;i++) maxitems=max(maxitems,dijkstra(i));
    cout << maxitems;
}