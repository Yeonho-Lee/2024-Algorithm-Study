#include <stdio.h>
#include <string.h>
char a[20002][51], temp[20002][51];

int vocajud(char a[], char b[]){
    if(strlen(a)<strlen(b)) return 1;
    else if(strlen(a)>strlen(b)) return 0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]<b[i]) return 1;
        else if(a[i]>b[i]) return 0;
    }
    return 0;
} // strcmp(a,b) 결과값으로도 참고 가능

int main(){
    int n,size=1, firstpointer=0, lastpointer=1;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%s", a[i]);
    while(size<2*n){
        int left=0, right=0, rightmaxsize=n-lastpointer;
        if(rightmaxsize>=size) rightmaxsize=size;
        if(rightmaxsize>=1) {
            for(int i=0;i<size+rightmaxsize;i++){
                if(left==size) { strcpy(temp[i], a[lastpointer+right]); right++; continue; }
                if(right==rightmaxsize) { strcpy(temp[i], a[firstpointer+left]); left++; continue; }
                if(vocajud(a[firstpointer+left], a[lastpointer+right])) { strcpy(temp[i], a[lastpointer+right]); right++; }
                else {strcpy(temp[i], a[firstpointer+left]); left++; }
            }
            for(int i=0;i<size+rightmaxsize;i++) strcpy(a[firstpointer+i], temp[i]);
        }
        firstpointer+=size*2;
        lastpointer+=size*2;
        if(firstpointer>=n) {
            size*=2;
            firstpointer=0;
            lastpointer=size;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(strcmp(a[i+1], a[i])!=0) printf("%s\n", a[i]);
    }
}

// 야매 Merge Sort
// Merge Sort의 나누는 과정 생략하고 size=1부터 합치는 식으로 진행함