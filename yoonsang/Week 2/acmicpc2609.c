#include <stdio.h>
int a[2][10000]={0};

int main(){
    int a,b,c=1,d=1;
    scanf("%d %d", &a, &b);
    while(d){
        for(int i=2;;i++){
          if(a%i==0 && b%i==0){ a/=i; b/=i; c*=i; break; }
          if(i>a || i>b) { d=0; break; }
        }
    }
    printf("%d\n%d", c, c*a*b);
}

//  1트에 해결!
//   백준 티어 : B1
// 굳