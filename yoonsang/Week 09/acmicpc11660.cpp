#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, xx1, yy1, xx2, yy2, a[1024][1025];
long long area;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> a[i][j];
            if(i==0 && j==0) continue;
            if(i==0) { a[i][j]+=a[i][j-1]; continue; }
            if(j==0) { a[i][j]+=a[i-1][j]; continue; }
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    while(m--) {
        cin >> xx1 >> yy1 >> xx2 >> yy2;
        xx1--; yy1--; xx2--; yy2--; // 0 1 0 1
        area = a[xx2][yy2];
        if(xx1!=0) area-=a[xx1-1][yy2];
        if(yy1!=0) area-=a[xx2][yy1-1];
        if(yy1!=0 && xx1!=0) area+=a[xx1-1][yy1-1];
        cout << area << '\n';
    }
    return 0;
}