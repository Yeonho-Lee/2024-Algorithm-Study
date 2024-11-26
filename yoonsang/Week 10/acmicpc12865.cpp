#include <iostream>
using namespace std;
int n, k, a[101][2], dp[101][100001]={}; // weight, value;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i][0] >> a[i][1];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(a[i-1][0]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], a[i-1][1]+dp[i-1][j-a[i-1][0]]);
        }
    }
    cout << dp[n][k];
}
// 이해 잘 안 됨
// https://howudong.tistory.com/106
//