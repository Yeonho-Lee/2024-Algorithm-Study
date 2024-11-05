#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <cmath>
int main(){
    int n, dis=1, max=0, maxnum, maxnum1=-4001;
    double sum=0;
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++) { scanf("%d", &arr[i]); sum+=arr[i];} 
    if(n==1) { printf("%d\n%d\n%d\n0", arr[0], arr[0], arr[0]); return 0; }
    std::sort(arr, arr+n);
    for(int i=0;i<n-1;i++) {
        if(arr[i+1]==arr[i]) dis++;
        else {
            if(dis==max && maxnum1==-4001) maxnum1=arr[i];
            if(dis>max) { max=dis; maxnum=arr[i]; maxnum1=-4001; }               
            dis=1;
        }
    }
    if(dis==max && maxnum1==-4001) maxnum1=arr[n-1];
    if(dis>max) { max=dis; maxnum=arr[n-1]; maxnum1=-4001; }
    if(maxnum1==-4001) maxnum1=maxnum;
    printf("%d\n%d\n%d\n%d", (int)round(sum/n), arr[n/2], maxnum1, arr[n-1]-arr[0]);
}