#include <iostream>
#include <vector>
#include <array>
using namespace std;
vector<array<int, 2>> graph[100001];
int n, temp[2], nn, d, dis[100001]={}, maax[2];
bool visited[100001]={};

void dfs(int node);
void process(int node);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> nn;
		while(1){
			cin >> temp[0];
			if(temp[0]==-1) break;
			cin >> temp[1];
			graph[nn].push_back({temp[0], temp[1]});
		}
	}
	process(1);
	process(maax[1]);
	cout << maax[0];
}

void dfs(int node){
	for(auto i:graph[node]) {
		if(!visited[i[0]]) {
			dis[i[0]]=dis[node]+i[1];
			visited[i[0]]=true;
			dfs(i[0]);
		}
	}
}

void process(int node){
	for(int i=1;i<=n;i++) {
		visited[i]=false;
		dis[i]=999'999'999;
	}
	dis[node]=0;
	visited[node]=true;
	maax[0]=-1;
	maax[1]=0;
	dfs(node);
	for(int i=1;i<=n;i++) {
		if(maax[0]<dis[i]) {
			maax[0]=dis[i];
			maax[1]=i;
		}
	}
}