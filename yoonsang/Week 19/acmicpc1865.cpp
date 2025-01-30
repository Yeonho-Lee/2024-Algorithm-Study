#include <iostream>
#include <vector>
#include <array>
using namespace std;
vector<array<int, 3>> graph, graphs;
int tc,n,m,w,s,e,t,dis[501];
bool flg;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> m >> w;
        graph.clear(); graphs.clear();
        for(int i=0;i<m;i++) {
            cin >> s >> e >> t;
            graphs.push_back({s,e,t});
            graphs.push_back({e,s,t});
        }
        for(int i=0;i<w;i++) {
            cin >> s >> e >> t;
            graph.push_back({s,e,-1*t});
        }
        for(auto i:graphs) {
            graph.push_back({i[0], i[1], i[2]});
        }
        flg=false;
        for(int i=1;i<=1;i++) {
            // 모든 간선을 모든 노드 번 검토하니까 출발 지점을 어디로 정하든 큰 상관이 없나...?
            for(int j=1;j<=n;j++) dis[j]=99999999;
            dis[i]=0;
            for(int j=0;j<n;j++) {
                for(auto k:graph){
                    if(dis[k[0]]+k[2]<dis[k[1]]) {
                        dis[k[1]]=dis[k[0]]+k[2];
                    }
                }
            }
            for(auto j:graph){
                if(dis[j[0]]+j[2]<dis[j[1]]) {
                    flg=true; break; 
                }
            }
            if(flg) break;
        }
        cout << (flg?"YES\n":"NO\n");
    }
}