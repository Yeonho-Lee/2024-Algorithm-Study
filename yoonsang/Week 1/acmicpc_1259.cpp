#include <stdio.h>

int main(){
    int num,cnt=0,a[6];
    while(1){
        scanf("%d",&num);
        if(!num) break;
        for(int j=0;;j++){
            a[j]=num%10;
            num/=10;
            if(num==0) { cnt=j+1; break; }
        }
        for(int j=0;j<cnt;j++){
            if(a[j]!=a[cnt-j-1]) { printf("no\n"); break; }
            if(j==cnt-1) printf("yes\n");
        }
    }  
}

//  2트에 해결 | WA 1
//   백준 티어 : B1
// 문제 똑바로 안 봐서 테스트케이스 n개 던져주고 반복하는 이야기로 이해하고 냈다가 WA 받음....