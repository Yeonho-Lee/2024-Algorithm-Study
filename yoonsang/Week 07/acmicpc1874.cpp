#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <cmath>
#include <stack>
int main(){
    int n,cnt=1;
    std::stack<int> st;
    scanf("%d", &n);
    int *a=(int*)malloc(sizeof(int)*(n+4));
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=n;i++) {
        if(i==n && a[i]==i) break;
        if(a[cnt]>=i) { st.push(i); }
        if(a[cnt]==i) {
            if(st.top()!=a[cnt]) {printf("NO"); return 0;} 
            cnt++; st.pop(); }
        if(a[cnt]<i){
            while(a[cnt]<i) {
                if(st.top()!=a[cnt]) {printf("NO"); return 0;}
                cnt++; st.pop();
                if(cnt>n) break;
            }
        }
    }
    while(st.size()) st.pop();
    cnt=1;
    for(int i=1;i<=n;i++) {
        if(i==n && a[i]==i) { printf("+\n-\n"); break; }
        if(a[cnt]>=i) { printf("+\n"); st.push(i); }
        if(a[cnt]==i) {
            printf("-\n"); cnt++; st.pop(); }
        if(a[cnt]<i) { 
            while(a[cnt]<i) {
                printf("-\n"); cnt++; st.pop();
                if(cnt>n) break;
            }
        }
    }
}