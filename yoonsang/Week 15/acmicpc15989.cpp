#include <iostream>
using namespace std;
int t, n;
long long dp[10001]={0,1,2,3,4,};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=5;i<=10000;i++){
        dp[i]=dp[i-3]+i/2+1;
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
}

// n=10
// 1 1 1 1 1 1 1 1 1 1    -1
//  2  1 1 1 1 1 1 1 1
//  2   2  1 1 1 1 1 1
//  2   2   2  1 1 1 1
//  2   2   2   2  1 1
//  2   2   2   2   2      -5

//       vv n=10-3일 때의 경우의 수
//   3   1 1 1 1 1 1 1     
//   3    2  1 1 1 1 1
//   3    2   2  1 1 1
//   3    2   2   2  1    
//   3     3   1 1 1 1
//   3     3    2  1 1    
//   3     3    2   2     
//   3     3     3   1    