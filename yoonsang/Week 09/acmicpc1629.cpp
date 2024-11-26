#include <iostream>
#include <cmath>
using namespace std;
long long n,m,l,a[33]; // n의 i제곱 = a[i]
int aa(int k){
    for(int i=0;i<33;i++) if(i==log2(k)) return a[i];
    return (a[(int)log2(k)]*aa(k-pow(2, (int)log2(k))))%l;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> l;
    a[0]=n%l;
    for(int i=1;i<33;i++) a[i]=(a[i-1]*a[i-1])%l;
    cout << aa(m);
}