#include <iostream>
#include <malloc.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,maxnum=0,a[501][501];
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];

    // I 미노
    for(int i=0;i<n;i++) for(int j=0;j<m-3;j++) maxnum=max(a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3],maxnum);
    for(int i=0;i<n-3;i++) for(int j=0;j<m;j++) maxnum=max(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j],maxnum);

    // O 미노
    for(int i=0;i<n-1;i++) for(int j=0;j<m-1;j++) maxnum=max(a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1],maxnum);

    // T 미노
    for(int i=0;i<n-1;i++) for(int j=0;j<m-2;j++) maxnum=max(a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i][j+1], max(a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1],maxnum));
    for(int i=0;i<n-2;i++) for(int j=0;j<m-1;j++) maxnum=max(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+1][j+1], max(a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i+1][j],maxnum));

    // S,Z 미노
    for(int i=0;i<n-1;i++) for(int j=0;j<m-2;j++) maxnum=max(a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2], max(a[i+1][j]+a[i+1][j+1]+a[i][j+1]+a[i][j+2],maxnum));
    for(int i=0;i<n-2;i++) for(int j=0;j<m-1;j++) maxnum=max(a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1], max(a[i][j+1]+a[i+1][j+1]+a[i+1][j]+a[i+2][j],maxnum));

    // L,J 미노
    for(int i=0;i<n-1;i++) for(int j=0;j<m-2;j++) maxnum=max(a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2], max(a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j], max(a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2], max(a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2],maxnum))));
    for(int i=0;i<n-2;i++) for(int j=0;j<m-1;j++) maxnum=max(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1], max(a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i][j], max(a[i][j]+a[i+1][j]+a[i+2][j]+a[i][j+1], max(a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i+2][j],maxnum))));
    cout << maxnum;
}