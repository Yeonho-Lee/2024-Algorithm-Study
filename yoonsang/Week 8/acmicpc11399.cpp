#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,sum=0;
    cin >> n;
    int *a=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++) cin >> a[i];
    std::sort(a, a+n);
    for(int i=0;i<n;i++) sum+=a[i]*(n-i);
    cout << sum << endl; 
}