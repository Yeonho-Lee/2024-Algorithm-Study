#include <iostream>
#include <cmath>
#include <malloc.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,length=0,lengthmax=0;
    cin >> n;
    int *a=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            if(i==j) continue;
            length=0;
            for(int k=0;k<n;k++) {
                if(a[k]==i || a[k]==j) length++;
                else {
                    lengthmax=max(length, lengthmax);
                    length=0;
                }
            }
            lengthmax=max(length, lengthmax);
            length=0;
        }
    }
    cout << lengthmax;
}