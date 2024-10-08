#include <stdio.h>
int a[3][51]={};

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d %d", &a[0][i], &a[1][i]);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if((a[0][j] > a[0][i]) && (a[1][j] > a[1][i])) a[2][i]++;
        }
        a[2][i]++;
    }
    for(int i=0;i<n;i++) printf("%d ", a[2][i]);
}

// 무난무난