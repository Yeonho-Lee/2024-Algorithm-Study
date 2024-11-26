#include <iostream>
using namespace std;
long long t,n,a[102]={0,1,1,1,2,2,};
int main(){
    for(int i=6;i<101;i++) a[i]=a[i-1]+a[i-5];
    cin >> t;
    while(t--) {
        cin >> n;
        cout << a[n] << '\n';
    }
}