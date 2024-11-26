#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m, a[18][18]={}, temp;
long long dp[17][17][3]={}; // 행, 열, 자세
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        cin >> a[i][j];
    }
    for(int i=1;i<=n+1;i++){
        a[n+1][i]=1; a[i][n+1]=1;
    }
    dp[1][2][0]=1;
    for(int i=3;i<=n;i++) {
        if(a[1][i]==1) break;
        dp[1][i][0]=1;
    }
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=n;j++) {
            if(a[i][j]!=0) continue; // 파이프 가는 위치가 0
            dp[i][j][0]=dp[i][j-1][1]+dp[i][j-1][0];
            dp[i][j][2]=dp[i-1][j][1]+dp[i-1][j][2];
            if(a[i-1][j]==0 && a[i][j-1]==0) {
                dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
            }
        }
    }
    cout << dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
} 