#include <stdio.h>
#include <string.h>
char a[20000][50], temp[20000][50];
int alen[20000],templen[20000],M;
int vocajud(char a[], char b[]){
    if(strlen(a)<strlen(b)) return 1;
    else if(strlen(a)>strlen(b)) return 0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]<b[i]) return 1;
        else if(a[i]>b[i]) return 0;
    }
    return 0;
}
int msort(int L, int R){
    if(L>=R) return 0;
    M=(L+R)/2;
    msort(L, M);
    msort(M+1, R);
    for(int i=L, l=L, r=M+1; l!=M+1 || r!=R+1; i++){
        if ((r!=R+1 && l<=M && vocajud(a[l], a[r])) || r==R+1) {
          for(int j=0;j<alen[l];j++)
            temp[i][j] = a[l][j];
          templen[i]=alen[l];
          printf("temp: %s / a: %s, l: %d\n", temp[i], a[l], l);
          l++;
        } else {
          for(int j=0;j<alen[r];j++)
            temp[i][j] = a[r][j];
          templen[i]=alen[r];
          printf("temp: %s / a: %s, r: %d\n", temp[i], a[r], r);
          r++;
        }
        printf("L: %d / i: %d / l: %d / r: %d %s %s %s\n", L,i,l,r,temp[i], a[l], a[r]);
    }
    for (int i=L; i<=R; i++) {
      for(int j=0;j<templen[i];j++)
        a[i][j] = temp[i][j];
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {scanf("%s", a[i]); alen[i]=strlen(a[i]);}
    msort(0, n-1);
    for(int i=0;i<n;i++){
        if(a[i-1]==a[i]) continue;
        printf("%s\n", a[i]);
    } 
}

// 미해결, Merge Sort 연습 겸 구현하고 이것저것 추가해서 하려는데 어렵다
// 기본적으로 Merge Sort와 같은데 숫자 대소 판단 부분을 문자열 판단 함수로 따로 빼서 구분함
// 다 잘 되는데 temp로 옮기고 이리저리 옮기는 과정에서 글자 길이 이슈로 출력이 itre 이렇게 됨

// week4에서 다른 방법으로 추가 구현 시도
#include <stdio.h>
#include <math.h>
#include <string.h>
// 정렬된 문자 배열
char a[20002][50];

// arr[n]은 문자열 길이가 n인 문자열의 a 배열에서의 시작 포인터
int arr[52]={0,};

// insert 구현(구현 연습 위해 내장 함수 사용하지 않음)
// 문자열 temp와 배열의 길이 i를 받아 배열 위치에 삽입
void insert(char temp[], size_t size, int i){
    for(int j=i;j>arr[strlen(temp)];j--){
        strcpy(a[j], a[j-1]);
    }
    strcpy(a[arr[strlen(temp)]], temp);
    for(int j=arr[strlen(temp)]+1;j<52;j++) arr[j]++;
}

int main(){
    int n;
    char temp[50];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", temp);
        insert(temp, strlen(temp), i);
    }
    for(int i=1;i<51;i++){
        if(arr[i]-arr[i-1]==0) continue;
        for(int j=arr[i];j<arr[i+1];j++){
            
        }
    }
}