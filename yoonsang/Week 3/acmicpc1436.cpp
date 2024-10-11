#include <stdio.h>
#include <math.h>

int main(){
    int n,j=0,cnt,multi;
    scanf("%d", &n);
    for(int i=666;j<n;i++){
        // 자리수 확인
        cnt=log10(i)+1;
        multi=1;
        // 맨 끝자리부터 세 자리씩 잘라서 확인
        for(int k=3;k<=cnt;k++){
            int l=i;
            l%=multi*1000;
            l/=multi;
            if(l==666){ j++; break; }
            multi*=10;
        }
        if(j==n) { printf("%d", i);}
    }
}

// 굿 무난무난