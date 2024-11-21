#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int t, n, a[2][100001], dp[3][100001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int j=0;j<2;j++) for(int i=0;i<n;i++) cin >> a[j][i];
        dp[0][0] = a[0][0]; dp[1][0]=a[1][0]; dp[2][0]=0;
        for(int i=1;i<n;i++) {
            dp[0][i]=max(dp[1][i-1], dp[2][i-1])+a[0][i];
            dp[1][i]=max(dp[0][i-1], dp[2][i-1])+a[1][i];
            dp[2][i]=max(dp[0][i-1], max(dp[1][i-1], dp[2][i-1]));
        }
        cout << max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1])) << '\n';
    }
}