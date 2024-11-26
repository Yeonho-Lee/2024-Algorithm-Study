#include <iostream>
#include <queue>
#include <array>
#include <string>
using namespace std;
int n,m,ladder[2][16],snake[2][16];
bool visited[101]={};
queue<array<int,2>> q; // location, turn
int bfs(){
    q.push({1,0});
    visited[1]=true;
    while(!q.empty()){
        int lo=q.front()[0], turn=q.front()[1];
        for(int i=1;i<=6;i++) {
            bool pass=false;
            int nextlo = lo+i;
            if(visited[nextlo]) continue;
            visited[nextlo]=true;
            if(nextlo==100) return turn+1;
            for(int i=0;i<m;i++) if(nextlo==snake[0][i]) { q.push({snake[1][i], turn+1}); visited[snake[1][i]]=true; pass=true; break; }
            for(int i=0;i<n;i++) if(nextlo==ladder[0][i]) { q.push({ladder[1][i], turn+1}); visited[ladder[1][i]]=true; pass=true; break; }
            if(!pass) { q.push({nextlo, turn+1}); }
        }
        q.pop();
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) { cin >> ladder[0][i] >> ladder[1][i]; }
    for(int i=0;i<m;i++) { cin >> snake[0][i] >> snake[1][i]; }
    cout << bfs();
}