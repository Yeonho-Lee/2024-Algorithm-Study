#include <cstdio>
#include <algorithm>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long int n, a[2001]={}, min[2000], minnum=1000000000000000001;
        scanf("%lld", &n);
        if(n==1) { scanf("%lld", &a[1999]); printf("1\n"); continue; }
        if(n==2) { scanf("%lld %lld", &a[0], &a[1]); printf("%lld\n", a[1]-a[0]); continue; }
        for(int i=0;i<n;i++) scanf("%lld", &a[i]);
        if(n%2==0) { // if even, a[0]--a[1], a[2]--a[3] then print min of them is ALWAYS minimum
            for(int i=0;i<n;i+=2){ min[i/2]=a[i+1]-a[i];}
            std::sort(min, min+n/2);
            printf("%lld\n", min[n/2-1]);
        }
        else { // if odd, check all cases? 
            for(long long int i=0;i<n;i++){
                long long int atemp[2001]={}, minus=0;
                for(long long int j=0;j<n;j++){
                    // left
                    if(i==j) { minus++; if(a[j]-1==-1) {atemp[j]=0;} atemp[j]=a[j]-1; }
                    atemp[j+minus]=a[j];
                }
                for(long long int k=0;k<(n+1);k+=2){ min[k/2]=atemp[k+1]-atemp[k]; }
                std::sort(min, min+n/2+1);
                if(min[n/2]<minnum) minnum=min[n/2];
                minus=0;
                for(long long int j=0;j<n;j++){
                    // right
                    if(a[j]+1==1000000000000000001) continue;
                    atemp[j+minus]=a[j];
                    if(i==j) { minus++; atemp[j+1]=a[j]+1; }
                }
                for(long long int k=0;k<(n+1);k+=2){ min[k/2]=atemp[k+1]-atemp[k]; }
                std::sort(min, min+n/2+1);
                if(min[n/2]<minnum) minnum=min[n/2];
            }
            printf("%lld\n", minnum);
        }
    }
}