#include <iostream>
#include <malloc.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    int *a=(int*)malloc(sizeof(int)*(n+2)), *b=(int*)malloc(sizeof(int)*(n+2));
    b[0]=0;
    cin >> a[1]; b[1]=a[1];
    for(int i=2;i<=n;i++) { cin >> a[i]; b[i] = b[i-1]+a[i]; }
    while(m--) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cout << b[temp2]-b[temp1-1] << '\n';
    }
}