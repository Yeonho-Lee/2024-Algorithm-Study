#include <iostream>
#include <unordered_map>
using namespace std;
#define mod 1'000'000'007
unordered_map<long long, long long> m;
long long n, a[18]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};

long long fi(long long inp){
    if(inp<18) return a[inp];
    if(inp%2==0) {
        long long a,b;
        if(m.find(inp/2)==m.end()) {
            a=fi(inp/2);
            m[inp/2]=a;
        } else a=m[inp/2];
        if(m.find(inp/2-1)==m.end()) {
            b=fi(inp/2-1);
            m[inp/2-1]=b;
        } else b=m[inp/2-1];
        return (a*((a+2*(b))%mod))%mod;
    } else {
        long long a,b;
        if(m.find(inp/2)==m.end()) {
            a=fi(inp/2);
            m[inp/2]=a;
        } else a=m[inp/2];
        if(m.find(inp/2+1)==m.end()) {
            b=fi(inp/2+1);
            m[inp/2+1]=b;
        } else b=m[inp/2+1];
        return (a*a%mod+b*b%mod)%mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cout << fi(n);
}

/*
f9
= f5f5 + f4f4

f10
= f5(f5+2f4)

f(2n+1)
= fnfn + f(n+1)f(n+1)

f(2n)
= fn(fn+2f(n-1))
*/