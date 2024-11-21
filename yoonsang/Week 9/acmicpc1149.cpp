#include <iostream>
using namespace std;
int n, temp, a[3][1001]={};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[0][i] >> a[1][i] >> a[2][i];
        a[0][i]+=min(a[1][i-1],a[2][i-1]);
        a[1][i]+=min(a[0][i-1],a[2][i-1]);
        a[2][i]+=min(a[0][i-1],a[1][i-1]);
    }
    cout << min(a[0][n], min(a[1][n], a[2][n]));
}
// dp 너무 어려워요...