#include <iostream>
using namespace std;
int r,c,t,a[1001][50][50]={},air,aircnt,summ=0;

int main(){
    cin >> r >> c >> t;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        cin >> a[0][i][j];
        if(a[0][i][j]==-1) {
            for(int k=1;k<=t;k++) a[k][i][j]=-1;
            air=i;
        }
    }
    for(int k=0;k<t;k++){
        for(int i=0;i<r;i++) { for(int j=0;j<c;j++) {
            aircnt=0;
            if(j>=1     && a[k][i][j-1]!=-1)    { aircnt++; a[k+1][i][j-1]+=a[k][i][j]/5; }
            if(j<c-1)                           { aircnt++; a[k+1][i][j+1]+=a[k][i][j]/5; }
            if(i>=1     && a[k][i-1][j]!=-1)    { aircnt++; a[k+1][i-1][j]+=a[k][i][j]/5; }
            if(i<=r-2   && a[k][i+1][j]!=-1)    { aircnt++; a[k+1][i+1][j]+=a[k][i][j]/5; }
            a[k+1][i][j]+=a[k][i][j]-aircnt*(a[k][i][j]/5);
        } }
        for(int i=air-1;i>=0;i--) a[k+1][i+1][0]=a[k+1][i][0];
        a[k+1][air-1][0]=-1;
        for(int i=air;i<r-1;i++) a[k+1][i][0]=a[k+1][i+1][0];
        a[k+1][air][0]=-1;
        for(int j=0;j<c-1;j++) {
            a[k+1][0][j]=a[k+1][0][j+1];
            a[k+1][r-1][j]=a[k+1][r-1][j+1];
        }
        for(int i=0;i<air-1;i++) a[k+1][i][c-1]=a[k+1][i+1][c-1];
        for(int i=r-1;i>air;i--) a[k+1][i][c-1]=a[k+1][i-1][c-1];
        for(int j=c-1;j;j--) {
            a[k+1][air-1][j]=a[k+1][air-1][j-1];
            a[k+1][air][j]=a[k+1][air][j-1];
        }
        a[k+1][air-1][1]=0; a[k+1][air][1]=0;
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) summ+=a[t][i][j];
    cout << summ+2;
}