#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b,fn="";
int arr[1001][1001]={}, nn, nnp, mm;

int main(){
    cin >> a >> b;
    for(int i=1;i<=a.length();i++) for(int j=1;j<=b.length();j++) {
        if(a[i-1]==b[j-1]) arr[i][j]=max(arr[i-1][j-1]+1, max(arr[i-1][j], arr[i][j-1]));
        else arr[i][j]=max(arr[i-1][j-1], max(arr[i][j-1], arr[i-1][j]));
    }
    nn=arr[a.length()][b.length()];
    cout << nn << '\n';
    nnp=a.length();
    for(int j=b.length();j;j--) {
        if(nnp==0) break;
        mm=max(arr[nnp-1][j-1], max(arr[nnp-1][j], arr[nnp][j-1]));
        if(mm==nn-1) {
            fn+=a[--nnp]; nn--;
        } else {
            if(arr[nnp-1][j]==nn) {
                nnp--; j++;
            }
        }
    }
    reverse(fn.begin(), fn.end());
    cout << fn;
}