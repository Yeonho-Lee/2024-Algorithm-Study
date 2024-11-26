#include <iostream>
#include <string>
using namespace std;
int arr[1001][1001]={};
string a,b;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for(int i=1;i<=a.length();i++) {
        for(int j=1;j<=b.length();j++){
            if(a[i-1]!=b[j-1]) arr[i][j]=max(arr[i-1][j], arr[i][j-1]);
            else arr[i][j]=arr[i-1][j-1]+1;
        }
    }
    cout << arr[a.length()][b.length()];
}
//