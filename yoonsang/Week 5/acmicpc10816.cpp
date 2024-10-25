#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
int a[500001],b[2][500001]={};

int main(){
    int n,m,temp,cnt=1;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    std::sort(a+0, a+n);
    std::fill_n(b[0], 500000, -10000001);
    b[0][0] = 0; b[1][0] = a[0];
    for(int i=1;i<n;i++) {
        if(a[i-1]!=a[i]) { b[0][cnt]=i; b[1][cnt]=a[i]; cnt++; }
    }
    b[0][cnt] = n; b[1][cnt] = 10000001;
    scanf("%d", &m);
    for(int i=0;i<m;i++) { 
        scanf("%d", &temp);
        if(temp<b[1][0]) { printf("0 "); continue; }
        if(b[1][cnt-1]<temp) { printf("0 "); continue; }
        int left=0, mid=cnt/2, right=cnt;
        while(1){
            if(temp==b[1][mid]) { printf("%d ", b[0][mid+1]-b[0][mid]); break; }
            if(right-left==1) { 
                if(temp==b[1][mid]) { printf("%d ", b[0][mid+1]-b[0][mid]); break; }
                else { printf("0 "); break; }
            }
            if(temp<b[1][mid]) { right=mid; mid=(left+mid)/2; }
            if(temp>b[1][mid]) { left=mid; mid=(mid+right)/2; }
        }
    }
}