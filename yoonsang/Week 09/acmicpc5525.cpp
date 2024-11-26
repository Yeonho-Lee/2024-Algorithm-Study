#include <iostream>
#include <string>
using namespace std;
int n,l,cnt=0,tot=0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> l;
    cin >> s;
    for(int i=2;i<l;i+=2){
        if(s.substr(i-2, 3)=="IOI") {
            cnt++;
            if(cnt>=n) tot++;
        }
        else cnt=0;
    }
    cnt=0;
    for(int i=3;i<l;i+=2){
        if(s.substr(i-2, 3)=="IOI"){
            cnt++;
            if(cnt>=n) tot++;
        }
        else cnt=0;
    }
    cout << tot;
}