#include <stdio.h>
int a[10000]={0};

int main(){
    int n,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        a[temp-1]++;
    }
    for(int i=0;i<10000;i++){
        for(int j=0;j<a[i];j++){
            printf("%d\n", i+1);
        }
    }
}

//  1트에 해결!
//   백준 티어 : B1
// 인터넷 찾아보고 돌린거라 노카운트