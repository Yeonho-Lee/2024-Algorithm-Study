#include <stdio.h>
#include <math.h>
int a[2000002]={0,};

int main(){
    int n,temp;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        a[temp+1000000]++;
    }
    for(int i=0;i<2000001;i++)
        if(a[i]==1) printf("%d\n", i-1000000);
}

// 다소 무식한 방법
// 인데 시간복잡도 O(n)이어서 제일 효율적이긴 함... 확장성이 망해서 그렇지