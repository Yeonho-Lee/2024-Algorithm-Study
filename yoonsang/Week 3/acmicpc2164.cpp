#include <stdio.h>
int a[1000001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) a[i]=i+1;
    int pointer=0, last=n;
    for(int i=0;i<n-1;i++){
        pointer++; 
        // pop = 포인터 주소를 1 더해

        a[last]=a[pointer];
        last++;
        pointer++;
        // push = 포인터 주소에 있는 애를 맨 뒤로 보내고 포인터 주소를 1 더해
    } 
    printf("%d", a[pointer]);
}

// 처음에 깡으로 배열 전체 업데이트 시도했다가 TLE 떠서 포인터 개념 가져와서 씀
// 잘 구현한 것 같음 찾아보니까 큐도 대충 이런 식으로 돌아가네