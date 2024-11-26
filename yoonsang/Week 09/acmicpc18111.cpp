#include <iostream>
#include <malloc.h>
#include <algorithm>
using namespace std;
int n,m,b,totalblocks,mini=256,maxi=0,timemin=2100000000,timea, height;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> b;
    totalblocks=b;
    int *a=(int*)malloc(sizeof(int)*(n*m+1));
    for(int i=0;i<n*m;i++) { 
        cin >> a[i]; 
        totalblocks+=a[i];
        if(mini>a[i]) mini=a[i]; 
        if(maxi<a[i]) maxi=a[i];
    }
    int high=totalblocks/(n*m);
    if(high<maxi) maxi=high;
    for(int i=mini;i<=maxi;i++){
        timea=0;
        for(int j=0;j<n*m;j++) {
            if(a[j]<i) timea+=i-a[j];
            else timea+=2*(a[j]-i);
        }
        if(timea<=timemin) { timemin=timea; height=i; }
    }
    cout << timemin << ' ' << height;
}