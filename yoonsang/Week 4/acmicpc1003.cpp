#include <stdio.h>

int main(){
    int n,temp,a[42][2]={{1,0},{0,1},{1,1},};
    for(int i=3;i<41;i++) for(int j=0;j<=1;j++) a[i][j]=a[i-1][j]+a[i-2][j];
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &temp);
        printf("%d %d\n", a[temp][0], a[temp][1]);
    }
}