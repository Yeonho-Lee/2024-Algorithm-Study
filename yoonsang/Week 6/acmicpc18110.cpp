#include <cstdio>
#include <queue>
#include <malloc.h>
#include <algorithm>
#include <cmath>
int main(){
    int n;
    double sum=0;
    scanf("%d", &n);
    if(n==0) { printf("0"); return 0;}
    int*arr=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    std::sort(arr, arr+n);
    double a=round(n*0.15), b=n-a;
    for(int i=(int)a;i<(int)b;i++){ sum+=arr[i];}
    printf("%d", (int)round(sum/(b-a)));
}