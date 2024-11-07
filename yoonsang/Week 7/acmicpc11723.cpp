#include <cstdio>
#include <cstring>
int main(){
    int n;
    scanf("%d", &n);
    bool arr[22]={};
    int tmp;
    char a[7];
    for(int i=0;i<n;i++){
        scanf("%s", a);
        if(!strcmp(a, "add")) { scanf("%d", &tmp); arr[tmp]=1; }
        if(!strcmp(a, "remove")) { scanf("%d", &tmp); arr[tmp]=0; }
        if(!strcmp(a, "check")) { 
            scanf("%d", &tmp);
            if(arr[tmp]) printf("1\n"); else printf("0\n"); }
        if(!strcmp(a, "toggle")) { 
            scanf("%d", &tmp);
            if(arr[tmp]) arr[tmp]=0; else arr[tmp]=1; }
        if(!strcmp(a, "all")) { for(int i=1;i<21;i++) arr[i]=1; }
        if(!strcmp(a, "empty")) { for(int i=1;i<21;i++) arr[i]=0; }
    }
}