#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <cmath>
#define MAX (long long)2147483647
int main(){
    int k, n;
    long long int sum;
    scanf("%d %d", &k, &n);
    int *a=(int*)malloc(sizeof(int)*(k+1));
    for(int i=0;i<k;i++) scanf("%d", &a[i]);
    long long int left=0, right=MAX+1, mid;
    for(int i=0;i<ceil(log2(MAX)+1);i++) {
        sum=0;
        mid = (left+right)/2;
        for(int j=0;j<k;j++) { sum+=(a[j]/mid); }
        if(sum<n) { right=mid; }
        else if(sum>=n) { left=mid; }
    }
    printf("%lld", mid);
}