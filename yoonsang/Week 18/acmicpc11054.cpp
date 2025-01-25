#include <iostream>
#include <cmath>
using namespace std;
int n, a[1000], dp[2][1002]={}, temp;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
    dp[0][0]=1; dp[0][1001]=-1; dp[1][n-1]=1; dp[1][1001]=-1;
    for(int i=1;i<n;i++){
        temp=1001;
        for(int j=0;j<i;j++) if(a[j]<a[i] && dp[0][temp]<=dp[0][j]) temp=j;
        if(temp==1001) dp[0][i]=1; else dp[0][i]=dp[0][temp]+1;
    }
	for(int i=n-2;i>=0;i--){
		temp=1001;
		for(int j=n-1;j>i;j--) if(a[j]<a[i] && dp[1][temp]<=dp[1][j]) temp=j;
		if(temp==1001) dp[1][i]=1; else dp[1][i]=dp[1][temp]+1;
	}
	int maxnum=0;
    for(int i=0;i<n;i++) maxnum=max(maxnum, dp[0][i]+dp[1][i]-1);
    cout << maxnum;
}