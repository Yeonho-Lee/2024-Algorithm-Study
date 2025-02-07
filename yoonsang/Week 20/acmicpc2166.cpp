#include <iostream>
#include <vector>
using namespace std;
long long n,a[2][10001];
double sum=0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[0][i] >> a[1][i];
        if(i) sum+=(a[0][i-1]*a[1][i]-a[0][i]*a[1][i-1]);
    }
    sum+=(a[0][n-1]*a[1][0]-a[0][0]*a[1][n-1]);
    sum/=2;
    cout.precision(1);
    cout << fixed;
    cout << abs(sum);
}

// https://darkpgmr.tistory.com/86