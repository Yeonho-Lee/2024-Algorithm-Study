#include <stdio.h>
#include <math.h>

int main(){
    int t,rsum,rdif,a[6];
    double length;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        for(int j=0;j<6;j++) scanf("%d", &a[j]);
        if(a[0]==a[3] && a[1]==a[4]){
            if(a[2]==a[5]) printf("-1\n");
            else printf("0\n");
            continue;
        }
        length=pow(pow(a[3]-a[0],2)+pow(a[4]-a[1],2), 0.5);
        rsum=a[2]+a[5];
        rdif=abs(a[2]-a[5]);
        if(length==rsum || length==rdif) { printf("1\n"); continue; }
        if(length > rsum) { printf("0\n"); continue; }
        if(length < rsum && length < rdif) { printf("0\n"); continue; }
        if(length < rsum && length > rdif) { printf("2\n"); continue; }
    }
}
