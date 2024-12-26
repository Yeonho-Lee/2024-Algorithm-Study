#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        while(x<=n*m) {
            if(x==y) { cout << x << '\n'; break; }
            if(x<y) x+=n;
            else y+=m;
        }
        if(x!=y) cout << "-1\n";
    }
}