#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,k,cnt=0,temp1,temp2;
int arr[102][102];
bool visited[102]={0,};
queue<int> q;
vector<int> graph[102];

void bfs(int node) {
    q.push(node);
    visited[node]=true;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        for(auto i:graph[node]) {
            if(!visited[i]) {
                q.push(i);
                visited[i]=true;
                cnt++;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    while(k--){
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    bfs(1);
    cout << cnt;
}