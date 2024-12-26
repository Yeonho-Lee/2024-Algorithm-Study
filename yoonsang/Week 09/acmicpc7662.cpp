#include <iostream>
#include <map>
#include <string>
using namespace std;
int t,n,num;
string s;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        map<int, int> m;
        cin >> n;
        while(n--){
            cin >> s >> num;
            if(s[0]=='I') {
                if(m.find(num)==m.end()) m.insert({num, 1});
                else m[num]++;
            }
            else {
                if(m.empty()) continue;
                if(num==1) {
                    auto i=prev(m.end());
                    if(i->second==1) m.erase(i);
                    else m[i->first]--;
                }
                else {
                    auto i=m.begin();
                    if(i->second==1) m.erase(i);
                    else m[i->first]--;
                }
            }
        }
        if(m.empty()) cout << "EMPTY\n";
        else {
            auto i=prev(m.end()); cout << i->first << ' ';
            auto j=m.begin(); cout << j->first << '\n';
        }
    }
}