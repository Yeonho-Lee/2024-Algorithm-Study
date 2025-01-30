#include <iostream>
#include <queue>
#include <array>
#include <vector>
#include <stack>
using namespace std;
priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
vector<array<int, 2>> v[1001];
stack<int> st;
int n,m,s,e,t,start,destination,dis[1001]={},cost,now,nnext,ncost,parent[1001]={};

void dijkstra(int start){
	q.push({0, start});
    while(!q.empty()){
        cost = q.top()[0], now=q.top()[1];
        q.pop();
        if(cost>dis[now]) continue;
        for(auto i:v[now]){
			nnext=i[1], ncost=dis[now]+i[0];
            if(ncost<dis[nnext]) {
                dis[nnext]=ncost;
				parent[nnext]=now;
                q.push({ncost, nnext});
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> s >> e >> t;
		v[s].push_back({t, e}); // cost, destination
	}
	cin >> start >> destination;
	for(int i=1;i<=n;i++) dis[i]=999'999'999;
	dis[start]=0;
	dijkstra(start);
	st.push(destination);
	while(parent[st.top()]) st.push(parent[st.top()]);
	cout << dis[destination] << '\n' << st.size() << '\n';
	while(!st.empty()) { cout << st.top() << ' '; st.pop(); }
}