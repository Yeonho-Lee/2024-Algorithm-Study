#include <iostream>
using namespace std;
int n, temp[3], arr[1002][3]={}, loc[1002][3]={}, result=999'999'999;
bool flg[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for(int a=0;a<3;a++) { // fix first house's color
        for(int j=0;j<3;j++) loc[0][j]=(a==j?arr[0][j]:999'999'999);
        for(int i=1;i<n;i++) {
            if(i==0) continue;
            loc[i][0]=arr[i][0]+min(loc[i-1][1], loc[i-1][2]);
            loc[i][1]=arr[i][1]+min(loc[i-1][0], loc[i-1][2]);
            loc[i][2]=arr[i][2]+min(loc[i-1][0], loc[i-1][1]);
        }
        loc[n-1][a]=999'999'999;
        result=min(result, min(loc[n-1][0], min(loc[n-1][1], loc[n-1][2])));
    }
    cout << result;
}

// https://0m1n.tistory.com/121
// 세상에 머리 좋은 사람들이 진짜 너무 많다.................