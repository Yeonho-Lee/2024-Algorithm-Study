#include <iostream>
#include <malloc.h>
#include <algorithm>
#include <cmath>
using namespace std;
long long n, m, length=0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int *a = (int*)malloc(sizeof(int)*(n+2));
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    for(int i=1;i<n;i++) {
        if(length+i*(a[n-i]-a[n-i-1])<m) length+=i*(a[n-i]-a[n-i-1]);
        else { cout << (a[n-i]-ceil((double)(m-length)/i)); return 0; }
    }
    cout << (a[0] - ceil((double)(m-length)/n)); return 0;
}