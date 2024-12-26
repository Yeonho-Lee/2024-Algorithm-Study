#include <iostream>
#include <string.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,a[302];
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    long long dp[2][306];
    memset(dp, 0, sizeof(dp));
    dp[0][1] = a[1];
    for(int i=2;i<=n;i++) {
        //dp[0][i+2] = max(dp[1][i], dp[0][i]) + a[i+2];
        //dp[1][i+1] = max(dp[0][i] + a[i], dp[1][i+1]);
        dp[0][i] = max(dp[1][i-2], dp[0][i-2]) + a[i];
        dp[1][i] = dp[0][i-1] + a[i];
    }
    cout << max(dp[0][n], dp[1][n]); 
}