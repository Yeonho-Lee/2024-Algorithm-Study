#include <iostream>
#include <queue>
using namespace std;
int t,n,cnt=0;
void a(int curr, int n){
    for(int i=1;i<4;i++) {
        if(curr+i==n) cnt++;
        else if(curr+i>n) continue;
        else a(curr+i, n);
    }
}
int main(){
    cin >> t;
    while(t--) {
        cnt=0;
        cin >> n;
        a(0, n);
        cout << cnt << '\n';
    }
}