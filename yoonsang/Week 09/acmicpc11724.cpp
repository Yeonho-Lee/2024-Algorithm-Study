#include <iostream>
#include <vector>
#include <malloc.h>
#include <cstring>
using namespace std;
vector<int> graph[1002];
bool visited[1002] = {};
int n,m, temp1, temp2,cnt=0;
void dfs(int node){
    visited[node]=true;
    for(auto i:graph[node]) {
        if(!visited[i]) dfs(i);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    for(int i=1;i<=n;i++) {
        if(!visited[i]) { dfs(i); cnt++; }
    }
    cout << cnt;
}