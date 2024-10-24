#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
int a[100001];

int main(){
    int n,m,temp;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    std::sort(a+0, a+n);
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        scanf("%d", &temp);
        int left=0, right=n, mid=n/2;
        for(int j=0;j<log2(n);j++){
            if(a[mid]==temp) break;
            if(a[mid] < temp) { left = mid; mid = (mid+right)/2; }
            if(a[mid] > temp) { right = mid; mid = (mid+left)/2; }
        }
        if(a[mid]==temp) { printf("1\n"); continue; }
        printf("0\n");
    }
}