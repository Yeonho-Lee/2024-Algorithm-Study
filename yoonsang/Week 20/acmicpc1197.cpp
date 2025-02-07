#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
int n,ee,s,e,t,uf[10001]={},sum=0;

void unions(int a, int b);
int find(int a);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> ee;
    while(ee--) {
        cin >> s >> e >> t;
        q.push({t, s, e});
    }
    for(int i=0;i<n;i++) uf[i]=i;
    while(!q.empty()) {
        t=q.top()[0]; s=q.top()[1]; e=q.top()[2]; q.pop();
        if(find(s)==find(e)) continue;
        unions(s, e);
        sum+=t;
    }
    cout << sum;
}

void unions(int a, int b) {
    a=find(a);
    b=find(b);
    if(a==b) return;

    if(a<b) uf[b]=a;
    else uf[a]=b;
}

int find(int a) {
    if(a==uf[a]) return a;
    return uf[a]=find(uf[a]);
}