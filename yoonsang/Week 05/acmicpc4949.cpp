#include <stdio.h>
#include <iostream>
#include <cstring> 
int a[100001];

int main(){
    while(1){
        char a[102]="",stack[102]="";
        std::cin.getline(a, 101);
        if(a[0]=='.') break;
        for(int i=0;i<strlen(a);i++){
            if(a[i]=='(') stack[strlen(stack)]='(';
            else if(a[i]=='[') stack[strlen(stack)]='[';
            else if(a[i]==')') { 
                if(stack[strlen(stack)-1]=='(') { stack[strlen(stack)-1]='\0'; continue; }
                else { stack[0]='0'; break; } }
            else if(a[i]==']') {
                if(stack[strlen(stack)-1]=='[') { stack[strlen(stack)-1]='\0'; continue; }
                else { stack[0]='0'; break; } }
            }
        if(strlen(stack)==0) printf("yes\n");
        else printf("no\n");
    }
}

// 진짜 이해 안 되는게 a[5] = "abcde"; 하면
// a[0]: a
// a[1]: b
// a[2]: c
// a[3]: d
// a[4]: e
// a[5]: \0
// 해서 잘 들어가야 하는게 아닌가? 왜 오류나지