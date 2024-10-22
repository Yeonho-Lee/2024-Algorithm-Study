<<<<<<< HEAD
#include <stdio.h>
#include <math.h>

int main(){
    int n,temp;
    char a[10]={0,};
    scanf("%d", &n);
    temp=n;
    for(int i=0;i<=log10(n);i++)
        { a[temp%10]++; temp/=10; }
    for(int i=9;i>=0;i--)
        { while(a[i]>=1) { printf("%d", i); a[i]--; } }
=======
#include <stdio.h>
#include <math.h>

int main(){
    int n,temp;
    char a[10]={0,};
    scanf("%d", &n);
    temp=n;
    for(int i=0;i<=log10(n);i++)
        { a[temp%10]++; temp/=10; }
    for(int i=9;i>=0;i--)
        { while(a[i]>=1) { printf("%d", i); a[i]--; } }
>>>>>>> d6604491d782edde6ceefbeb59a6859f01f13756
}