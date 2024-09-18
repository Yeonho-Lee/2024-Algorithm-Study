#include <stdio.h>

int main(){

    int n,m,minimum=64,cnt,temp;
    char a[50][50];
    
    // pattern set
    char b[8][9]={"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
    char b1[8][9]={"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
    
    // data input
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%s", a[i]);
    
    // compare arr 'a'(in each 8x8) to the pattern sets and check how different
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

// solved in    19 att. | 외부 디버깅 툴 사용(Dev C++)
// WA 5 | RTE 0 | CTE 9 | TLE 4
// 오랜만에 C++ 잡아서 파이썬식 문법을 자주 씀.. print(minimum)도 그렇고 배열 대괄호로 초기화함

// solved at: 2024. 09. 18. 16:00:59
//                 Difficulty : Silver 4
// solved.ac Tier: 0,487(+06) : Silver 3