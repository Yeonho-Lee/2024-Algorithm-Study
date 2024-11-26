#include <iostream>
#include <malloc.h>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n,m,v,temp1,temp2;
set<int> visited, graph[1001];
queue<int> q;
void dfs(int v){
    cout << v << ' ';
    visited.insert(v);
    for(auto i:graph[v]){
        if(visited.find(i)==visited.end()) dfs(i);
    }
}
void bfs(int v){
    q.push(v);
    visited.insert(v);
    while(!q.empty()){
        cout << q.front() << ' ';
        for(auto i:graph[q.front()]) 
            if(visited.find(i)==visited.end()) { q.push(i); visited.insert(i);}
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> v;
    for(int i=0;i<m;i++) {
        cin >> temp1 >> temp2;
        graph[temp1].insert(temp2);
        graph[temp2].insert(temp1);
    }
    dfs(v);
    cout << '\n';
    visited.clear();
    bfs(v);
}