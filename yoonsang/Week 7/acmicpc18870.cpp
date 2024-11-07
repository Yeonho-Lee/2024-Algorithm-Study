#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <cmath>
int main(){
    int n, cnt=1;
    scanf("%d", &n);
    int *a=(int*)malloc(sizeof(int)*(n+1)), *arr=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++) { scanf("%d", &a[i]); arr[i]=a[i]; }
    std::sort(a, a+n);
    for(int i=1;i<n;i++) { if(a[i-1]!=a[i]) { a[cnt]=a[i]; cnt++; } }
    for(int i=0;i<n;i++){
        int left=0, right=cnt;
        for(int j=0;j<ceil(log2(cnt)+1);j++){
            int mid=(left+right)/2;
            if(a[mid]<arr[i]) { left=mid; }
            else if(a[mid]>arr[i]) { right=mid; }
            else { printf("%d ", mid); break; }
        }
    }
}