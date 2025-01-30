#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a,b,c,ans;
int n,m,maxx,amax,bmax,temp;

int main(){
    cin >> n;
    for(int i=0;i<n;i++) { cin >> temp; a.push_back(temp); }
    cin >> m;
    for(int i=0;i<m;i++) { cin >> temp; b.push_back(temp); }
    while(!(a.empty() || b.empty())) {
        amax=*max_element(a.begin(), a.end()); bmax=*max_element(b.begin(), b.end());
        if(amax==bmax) {
            while(a[0]!=amax) a.erase(a.begin());
            while(b[0]!=bmax) b.erase(b.begin());
            c.push_back(a[0]); a.erase(a.begin()); b.erase(b.begin());
        } else if(amax<bmax) { for(int i=0;i<b.size();i++) if(b[i]==bmax) { b.erase(b.begin()+i); i--; } } 
          else               { for(int i=0;i<a.size();i++) if(a[i]==amax) { a.erase(a.begin()+i); i--; } }
    }
    if(c.size()==0) { cout << 0; return 0; }
    cout << c.size() << '\n';
    for(auto i:c) cout << i << ' ';
}