#include <iostream>
#include <cmath>
using namespace std;
int n,r,c;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r >> c;
    int a[16]={};
    long long cnt=0;
    for(int i=n;i;i--){
        if(r>=pow(2,i-1)) { a[i]+=2; r-=pow(2,i-1); }
        if(c>=pow(2,i-1)) { a[i]++; c-=pow(2,i-1); }
        cnt+=a[i]*pow(4,i-1);
    }
    cout << cnt;
}