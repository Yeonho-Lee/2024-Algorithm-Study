#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <cstring>
using namespace std;
vector<array<int, 2>> graph[101];
int n,m,temp[3],costs[101],cost,curr,ncity,ncost;

void dijkstra(int start){
	costs[start]=0;
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({0, start});
    while(!q.empty()){
        cost=q.top()[0], curr=q.top()[1];
        q.pop();
        if(cost>costs[curr]) continue;
        for(auto i:graph[curr]) {
            ncity=i[1], ncost=costs[curr]+i[0];
            if(ncost<costs[ncity]) {
                costs[ncity] = ncost;
                q.push({ncost, ncity});
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> temp[0] >> temp[1] >> temp[2];
		graph[temp[0]].push_back({temp[2], temp[1]}); // cost, dest
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) costs[j]=987654321;
		dijkstra(i);
		for(int j=1;j<=n;j++) cout << (costs[j]==987654321?0:costs[j]) << ' ';
		cout << '\n';
	}
}