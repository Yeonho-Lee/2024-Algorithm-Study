#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,temp1,temp2;
vector<pair<int, int>> v;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp1 >> temp2;
        v.push_back({temp2, temp1});
    }
    sort(v.begin(), v.end());
    int cnt=1,end=v.begin()->first, first=1;
    for(auto i:v){
        if(i.first==i.second) { 
            cnt++;
            end=i.first; 
            if(first) cnt--;
            first=0;
            continue; }
        if(end!=i.first && i.second >= end) {
            cnt++; end=i.first;
        }
        first=0;
    }
    cout << cnt;
}