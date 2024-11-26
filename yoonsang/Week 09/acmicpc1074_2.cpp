#include <iostream>
#include <cmath>
using namespace std;
int n,r,c;
long long z(int n){
    int cnt=0;
    if(r>=pow(2,n-1)) { r-=pow(2,n-1); cnt+=2; }
    if(c>=pow(2,n-1)) { c-=pow(2,n-1); cnt++; }
    if(n) return cnt*pow(4,n-1)+z(n-1);
    else return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r >> c;
    int a[16]={};
    long long cnt=z(n);
    cout << cnt;
}