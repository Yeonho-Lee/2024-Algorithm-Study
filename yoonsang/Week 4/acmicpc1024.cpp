#include <stdio.h>
#include <ctype.h>

int main(){
    double n,l;
    scanf("%lf %lf", &n, &l);
    if(l*(l-1)/2 > n) { printf("-1"); return 0; }
    for(double i=l;i<=100;i++){
        int a=n/i;
        if((int)i%2==1 && (n/i)-a==0 && (n/i)-(i-1)/2>=0) {
            for(int j=0;j<i;j++) printf("%d ", (int)(a-(i-1)/2+j));
            return 0;
        } else if((int)i%2==0 && (n/i)-a==0.5 && a-i/2+1>=0){
            for(int j=0;j<i;j++) printf("%d ", (int)(a-i/2+1+j));
            return 0;
        }
    }
    printf("-1");
}
