#include <iostream>
using namespace std;
int n, m, p, q, a[2001];
bool odd[2001][2001]={}, even[2001][2001]={};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) {
        odd[i][i]=true;
        for(int j=1;;j++) {
            if(i-j<=0 || i+j>n) break;
            if(odd[i][i+j-1] && a[i+j]==a[i-j]) {
                odd[i][i+j]=odd[i][i-j]=true;
            } else break;
        }
    }
    for(int i=1;i<=n;i++) {
        if(a[i]==a[i+1]) {
            even[i][i]=even[i][i+1]=true;
            for(int j=1;;j++) {
                if(i-j<=0 || i+j+1>n) break;
                if(even[i][i-j+1] && a[i-j]==a[i+j+1]) {
                    even[i][i-j]=even[i][i+j+1]=true;
                } else break;
            }
        }
    }
    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> p >> q;
        if((p-q)%2==0) { // odd
            cout << odd[(p+q)/2][(p+q)/2-(q-p)/2] << '\n';
        } else { // even
            cout << even[(p+q)/2][(p+q)/2-(q-p)/2] << '\n';
        }
    }
}