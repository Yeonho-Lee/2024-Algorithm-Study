#include <iostream>
using namespace std;
long long n, s, a[100001], pstart=0, pend=1, psize=999'999, psum=0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i=0;i<n;i++) cin >> a[i];
    a[n]=200'000'000;
    psum+=a[0];
    while(pend<=n){
        if(s<=psum) {
            psize=min(psize, pend-pstart);
            psum-=a[pstart++];
        } else psum+=a[pend++];
    }
    cout << (psize==999'999?0:psize);
}
