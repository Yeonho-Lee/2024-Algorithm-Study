#include <iostream>
using namespace std;
int n, a[100001], pp1, pp2, difmin=2'000'000'000, ppsave[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    pp1=0; pp2=n-1;
    while(pp1!=pp2) {
        if(abs(a[pp1]+a[pp2])<difmin) {
            ppsave[0]=pp1; ppsave[1]=pp2;
            difmin=abs(a[pp1]+a[pp2]);
        }
        if(difmin==0) break;
        if(abs(a[pp1])<a[pp2]) pp2--;
        else pp1++;
    }
    cout << a[ppsave[0]] << ' ' << a[ppsave[1]];
}