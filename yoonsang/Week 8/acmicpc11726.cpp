#include <iostream>
#include <malloc.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    long long num[1000]={0,1,2,};
    cin >> n;
    for(int i=3;i<=n;i++) { num[i]=(num[i-1]+num[i-2])%10007; }
    cout << num[n];
}

// * 혼자 힘으로 해결하지 못함
// DP 점화식... 찾기가 많이 힘드네요 