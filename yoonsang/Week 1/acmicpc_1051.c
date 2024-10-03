#include <stdio.h>
char arr[50][50];

int main(){
  int n,k,maximum=1;
  char c;
  scanf("%d %d", &n, &k);
  for(int i=0;i<n;i++) scanf("%s", arr[i]);
  for(int a=0;a<10;a++){
    c=a+48;
    for(int i=0;i<n;i++){ for(int j=0;j<k;j++){
      if(arr[i][j]==c){
        for(int l=j+1;l<k;l++){
          if(arr[i][l]==c) {
            for(int m=i+1;m<n;m++){
              if(arr[m][j]==arr[m][l] && arr[m][j]==c && (l-j)==(m-i) && (l-j+1)*(m-i+1)>=maximum) maximum=(l-j+1)*(m-i+1);
    }}}}}}
  }
  printf("%d", maximum);
}

//  3트에 해결 | WA 2
//   백준 티어 : S3
// 괜찮은 난이도 (아마)비효율적인 아이디어 더러운 코드
// 20분 정도 고민하고 푼 듯