#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,temp;
bool visited[101];
vector<int> graph[101];
void dfs(int node){
    for(auto i:graph[node]){
        if(!visited[i]) {
            visited[i]=true;
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++) {
        cin >> temp;
        if(temp) graph[i].push_back(j);
    }}
    for(int i=0;i<n;i++) {
        memset(visited, false, 101);
        dfs(i);
        for(int j=0;j<n;j++) cout << (int)visited[j] << ' ';
        cout << '\n';
    }
}