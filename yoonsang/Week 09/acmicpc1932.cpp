#include <iostream>
#include <cmath>
using namespace std;
int n, a[500][501], maxnum=0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cin >> a[i][j];
            if(j==0) { a[i][0]+=a[i-1][0]; continue; }
            if(j==i) { a[i][i]+=a[i-1][i-1]; continue; }
            a[i][j]+=max(a[i-1][j-1], a[i-1][j]);
        }
    }
    for(int i=0;i<n;i++) maxnum=max(a[n-1][i], maxnum);
    cout << maxnum;
}