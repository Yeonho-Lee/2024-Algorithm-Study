#include <iostream>
using namespace std;
int n, temp[3], m[2][3][2]={};
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> temp[0] >> temp[1] >> temp[2];
        if(i==0){
            for(int j=0;j<3;j++) { 
                m[0][j][0] = temp[j];
                m[1][j][0] = temp[j];
            }
            continue;
        }
        //min
        m[0][0][1] = temp[0] + min(m[0][0][0], m[0][1][0]);
        m[0][1][1] = temp[1] + min(m[0][0][0], min(m[0][1][0], m[0][2][0]));
        m[0][2][1] = temp[2] + min(m[0][1][0], m[0][2][0]);
        for(int j=0;j<3;j++) m[0][j][0]=m[0][j][1];

        //max
        m[1][0][1] = temp[0] + max(m[1][0][0], m[1][1][0]);
        m[1][1][1] = temp[1] + max(m[1][0][0], max(m[1][1][0], m[1][2][0]));
        m[1][2][1] = temp[2] + max(m[1][1][0], m[1][2][0]);
        for(int j=0;j<3;j++) m[1][j][0]=m[1][j][1];
    }
    cout << max(m[1][0][0], max(m[1][1][0], m[1][2][0])) << ' ' << min(m[0][0][0], min(m[0][1][0], m[0][2][0]));
}