#include <iostream>
using namespace std;
int n,m,s,temp;
bool dp[51][1001]={};
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    dp[0][m]=true;
    for(int i=1;i<=n;i++){
        cin >> temp;
        for(int j=0;j<=s;j++) {
            if(j-temp>=0 && dp[i-1][j-temp]) dp[i][j]=true;
            if(j+temp<=s && dp[i-1][j+temp]) dp[i][j]=true;
        }
    }
    for(int i=s;i>=0;i--) 
        if(dp[n][i]) { cout << i; return 0; }
    cout << -1; return 0;
}