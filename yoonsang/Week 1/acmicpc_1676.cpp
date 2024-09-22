#include <stdio.h>

int main(){
    int n,num=1,cnt=0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        num*=i;
        while(num%10==0) {num/=10; cnt++;}
        if(num>1000) num=num%1000;
    }
    printf("%d", cnt);
}

//  3트에 해결 | WA 2
//   백준 티어 : S5
// 아이디어 자체는 효율적이고 괜찮았는데 처음 코드 짤 때 일의 자리만 남겨두는 바람에
// xxx125 * 8 = 1000이지만 xxxxx5 * 8 = 20으로 계산하는 문제가 발생함
// 일의 자리가 아니라 백의 자리까지 남겨두게 개선해 해결(인터넷 서칭)