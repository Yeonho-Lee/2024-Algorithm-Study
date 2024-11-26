#include <stdio.h>
#include <stdlib.h>

int main(){
  char a[3][9];
  int b,c;
  scanf("%s %s %s", a[0], a[1], a[2]);
  for(int i=0;i<3;i++){
    b=atoi(a[i]);
    if(b==0) continue;
    else{ c=b+3-i; break; }
  }
  if(c%3==0){
    if(c%5==0) { printf("FizzBuzz"); return 0; }
    printf("Fizz"); return 0;
  }
  if(c%5==0) { printf("Buzz"); return 0; }
  printf("%d", c);
}

//  1트에 해결!
//   백준 티어 : B1
// 13번 줄부터 18번 줄까지 뭔가 어떻게 할 수 있을 것 같은데
// 어떻게 해야 할지 모르겠음 switch case로 저게 되나?