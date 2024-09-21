#include <stdio.h>

int arr[15]={1,1,2,6,24,120,720,0,};
int fac(int a){
    if(arr[a]!=0) return arr[a];
    else { int b=a*fac(a-1); arr[a]=b; return b; } 
}

int main() {
    int n,k,result=1;
    scanf("%d %d", &n, &k);
    
    printf("%d", fac(n)/(fac(k)*fac(n-k)));
}

//  4트에 해결 | WA 0 | RTE 2 | CTE 1 | TLE 0
//   백준 티어 : B1
// 이번에는 arr[-1] 사용하라 해서 오류뱉게 함 재귀 문제 어케 더 해보자