#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
string temp;
unordered_set<string> sh;
set<string> s;
int n,k,cnt=0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> temp;
        sh.insert(temp);
    }
    for(int i=0;i<k;i++) {
        cin >> temp;
        if(sh.find(temp)!=0) {
            cnt++;
            s.insert(temp);
        }
    }
    cout << cnt << '\n';
    for(auto i:s) cout << i << '\n';
}