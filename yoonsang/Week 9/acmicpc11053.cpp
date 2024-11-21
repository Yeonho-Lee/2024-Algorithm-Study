#include <iostream>
using namespace std;
int n, a[1002], dp[1002]={}, cnt=1;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0]=0; a[0]=-1;
    dp[1]=1; 
    for(int i=2;i<=n;i++){
        int temp=0;
        for(int j=1;j<i;j++) if(a[j]<a[i] && dp[temp]<=dp[j]) temp=j;
        if(temp==0) dp[i]=1; else dp[i]=dp[temp]+1;
    }
    int maxnum = 0;
    for(int i=1;i<=n;i++) maxnum=max(dp[i], maxnum);
    cout << maxnum;
}