#include <iostream>
#include <numeric>
using namespace std;
long long result=0, temp;
int m, n, s, g;

long long powpow(int n, int pp){
    if(pp==1) return n;
    if(pp%2) return n*powpow(n,pp-1)%1'000'000'007;
    long long temp=powpow(n,pp/2);
    return temp*temp%1'000'000'007;
}

int main(){
    cin >> m;
    while(m--){
        cin >> n >> s;
        g=gcd(n,s);
        n/=g; s/=g;
        result+=s*powpow(n, 1'000'000'005)%1'000'000'007;
        result%=1'000'000'007;
    }
    cout << result;
}