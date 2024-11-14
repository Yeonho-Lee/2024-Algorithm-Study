#include <iostream>
#include <string>
#include <map>
using namespace std;
int t,n;
int main(){
    cin >> t;
    while(t--) {
        map<string, int> m;
        long long cnt=1;
        cin >> n;
        string temp1, temp2;
        while(n--) {
            cin >> temp1 >> temp2;
            if(m.find(temp2)==m.end()) m.insert({temp2, 1});
            else m[temp2]++;
        }
        for(auto i:m){ cnt*=(i.second+1); }
        cout << cnt-1 << '\n';
    }
}