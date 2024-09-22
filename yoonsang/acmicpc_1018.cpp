#include <stdio.h>

int main(){

    int n,m,minimum=64,cnt,temp;
    char a[50][50];
    
    // 패턴잡고      | [8][8]하니까 오류 뱉던데 왜그런지 몰라서 배열공부 다시 해야함
    char b[8][9]={"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
    char b1[8][9]={"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
    
    // 데이터 넣고
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%s", a[i]);
    
    // 입력받은 데이터에서 8*8 사이즈로 하나씩 돌려가면서 잡아둔 패턴이랑 얼마나 다른지 확인함
    for(int i=0;i<=n-8;i++) for(int j=0;j<=m-8;j++){
        cnt=0;
        for(int k=0;k<8;k++) for(int l=0;l<8;l++)
            if(a[i+k][j+l]!=b[k][l]) cnt++;
        if(cnt<minimum) minimum=cnt;
        cnt=0;
        for(int k=0;k<8;k++) for(int l=0;l<8;l++)
            if(a[i+k][j+l]!=b1[k][l]) cnt++;
        if(cnt<minimum) minimum=cnt;
    }
    printf("%d",minimum);
}

// 19트에 해결 | WA 5 | CTE 9 | TLE 4
//   백준 티어 : S4
// 오랜만에 C++ 잡아서 파이썬식 문법을 자주 씀.. print(minimum)도 그렇고 배열 대괄호로 초기화함