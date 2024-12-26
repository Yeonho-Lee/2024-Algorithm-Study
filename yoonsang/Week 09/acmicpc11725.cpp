#include <iostream>
#include <vector>
using namespace std;
int n, temp1, temp2, tree[100001];
bool visited[100001]={};
vector<int> graph[100001];
void dfs(int d){
    for(auto i:graph[d]) {
        if(!visited[i]) {
            visited[i]=true;
            tree[i]=d;
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++) {
        cin >> temp1 >> temp2;
        if(temp1!=1) graph[temp2].push_back(temp1);
        if(temp2!=1) graph[temp1].push_back(temp2);
    }
    visited[1]=true;
    dfs(1);
    for(int i=2;i<=n;i++) cout << tree[i] << '\n';
}