#include <stdio.h>
#include <iostream>
#include <cstring>
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char a[51]="",stack[51]="";
        scanf("%s", a);
        for(int i=0;i<strlen(a);i++){
            if(a[i]=='(') stack[strlen(stack)]='(';
            else if(a[i]==')') { 
                if(stack[strlen(stack)-1]=='(') { stack[strlen(stack)-1]='\0'; continue; }
                else { stack[0]='0'; break; } }
            }
        if(strlen(stack)==0) printf("YES\n");
        else printf("NO\n");
    }
}