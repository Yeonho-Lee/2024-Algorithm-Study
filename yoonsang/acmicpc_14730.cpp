#include <stdio.h>
int arr[2][100]={0};

int main(){
    int n,result=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &arr[0][i], &arr[1][i]);
        if(arr[1][i]==0) break;
        result+=arr[0][i]*arr[1][i];
    }
    printf("%d", result);
}

//  3트에 해결 | WA 0 | RTE 0 | CTE 2 | TLE 0
//   백준 티어 : S5
// 굳
// B3~B4정도에 있어도 될 난도