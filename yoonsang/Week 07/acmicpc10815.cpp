#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <cmath>
int main(){
    int n,m,temp;
    scanf("%d", &n);
    int *a=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    std::sort(a, a+n);
    for(int i=0;i<m;i++) {
        scanf("%d", &temp);
        int left=0, right=n,mid;
        for(int j=0;j<ceil(log2(n));j++){
            mid=(left+right)/2;
            if(a[mid]<temp) left=mid;
            else if(a[mid]>temp) right=mid;
        }
        if(a[mid]==temp) printf("1 ");
        else printf("0 ");
    }
}