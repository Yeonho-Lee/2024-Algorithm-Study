#include <iostream>
using namespace std;
int n, k, a[101][2], weight=0, value=0, maxvalue=0;
bool collected[101] = {};
void backtracking(int d){
    if(d==n) return;
    for(int i=d;i<n;i++){
        if(collected[i]) continue;
        if(weight+a[i][0]>k) continue;
        collected[i]=true; weight+=a[i][0]; value+=a[i][1];
        maxvalue=max(maxvalue, value);
        backtracking(d+1);
        collected[i]=false; weight-=a[i][0]; value-=a[i][1];
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> a[i][0] >> a[i][1];
    }
    backtracking(0);
    cout << maxvalue;
}