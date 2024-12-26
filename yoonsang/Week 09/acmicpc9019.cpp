#include <iostream>
#include <string>
#include <queue>
#include <array>
using namespace std;
string bfs(int s, int target){
    bool visited[10001]={};
    queue<pair<int, string>> q;
    q.push({s, ""});

    while(!q.empty()){
        if(q.front().first==target) return q.front().second;

        int curr[5]={q.front().first,};
        curr[1]=(curr[0]*10+curr[0]/1000)%10000;
        curr[2]=curr[0]/10+(curr[0]%10)*1000;
        if(curr[0]==0) curr[3]=9999; else curr[3]=curr[0]-1;
        curr[4]=(curr[0]*2)%10000;

        string qq[5]={"", "L", "R", "S", "D"};

        for(int i=1;i<5;i++){
            if(!visited[curr[i]]) {
                visited[curr[i]]=true;
                q.push({curr[i], q.front().second+qq[i]});
            }
        }
        q.pop();
    }
    return "";
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int s, target;
        cin >> s >> target;
        cout << bfs(s, target) << '\n';
    }
}