#include <iostream>
#include <malloc.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    long long num[1000]={0,1,3,};
    cin >> n;
    for(int i=3;i<=n;i++) { num[i]=(num[i-1]+2*num[i-2])%10007; }
    cout << num[n];
}