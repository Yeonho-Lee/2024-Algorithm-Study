#include <stdio.h>
int a[100000], c[201];
char b[100000][101];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) { scanf("%d %s", &a[i], b[i]); c[a[i]]++; }
    for(int i=1;i<=200;i++){
        if(c[i]==0) continue;
        for(int j=0;j<n;j++) {
            if(a[j]==i) printf("%d %s\n", a[j], b[j]);
        }
    }
}

// 무난무난하긴 한데 더 효율적인 방법이 있을 것 같기도
// O(n)이긴 한데...