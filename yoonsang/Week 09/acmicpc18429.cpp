#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,a[9],sum=0,cnt=0;
bool used[9]={};
vector<int> v;
void backtracking(int d){
    if(d==n) {
        int temp=0;
        for(int i=0;i<n;i++) temp+=v[i];
        if(temp>=0) cnt++;
        return;
    }
    for(int i=0;i<n;i++) {
        if(used[i] || sum+a[i]<0) continue;
        used[i]=true;
        sum+=a[i];
        v.push_back(a[i]);
        backtracking(d+1);
        v.pop_back();
        used[i]=false;
        sum-=a[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) { cin >> a[i]; a[i]-=m; }
    backtracking(0);
    cout << cnt;
}