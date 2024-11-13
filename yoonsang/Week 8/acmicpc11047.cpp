#include <iostream>
using namespace std;
int main(){
    int n,k,a[11];
    long long cnt=0;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=n-1;i>=0;i--) {
        if(a[i]>k) continue;
        cnt+=k/a[i];
        k-=a[i]*(k/a[i]);
    }
    cout << cnt;
}