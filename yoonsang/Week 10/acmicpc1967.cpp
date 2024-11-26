#include <iostream>
#include <vector>
#include <array>
using namespace std;
int n, temp[3], maxsum=0;
vector<array<int, 2>> v[10001];
int dfs(int node){
    if(v[node].size()==0) return 0;
    int nodesum=0, nodemax=0, max1=0, max2=0;
    for(auto i:v[node]){
        int a=0;
        if(v[i[0]].size()!=0) a=dfs(i[0]);
        nodemax=max(nodemax, a+i[1]);
        if(max1<=a+i[1]) { max2=max1; max1=a+i[1]; }
        else if(max2<=a+i[1]) max2=a+i[1];
    }
    nodesum=max1+max2;
    maxsum=max(nodesum, maxsum);
    return nodemax;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<3;j++) cin >> temp[j];
        v[temp[0]].push_back({temp[1], temp[2]});
    }
    int c=dfs(1);
    cout << max(maxsum, c);
}