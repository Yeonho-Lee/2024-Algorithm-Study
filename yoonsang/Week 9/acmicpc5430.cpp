#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;
int t;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        string s, p;
        int n, num=0, temp=0;
        cin >> s;
        cin >> n;
        cin >> p;
        int *a=(int*)malloc(sizeof(int)*(n+1));
        for(int i=0;i<p.length();i++){
            if(i==0) continue;
            if(isdigit(p[i])) { num*=10; num+=p[i]-'0'; }
            else { a[temp]=num; num=0; temp++; } 
        }
        int front=0, back=n-1;
        bool reverseflag=false, pass=false;
        for(int i=0;i<s.length();i++){
            if(n==0) {
                if(s[i]=='D') { cout << "error\n"; pass=true; break; }
                continue;
            }
            if((!reverseflag && front>back)||(reverseflag && back>front)) { cout << "error\n"; pass=true; break; }
            if(s[i]=='R') {
                if(reverseflag) reverseflag = false;
                else reverseflag = true;
                int temp=front;
                front=back;
                back=temp;
            }
            if(s[i]=='D') {
                if(reverseflag) front--;
                else front++;
                n--;
            }
        }
        if(pass) { delete(a); continue; }
        if(reverseflag) {
            cout << '[';
            for(int i=front;i>=back;i--) {
                cout << a[i];
                if(i!=back) cout << ',';
            }
            cout << "]\n";
        }
        else {
            cout << '[';
            for(int i=front;i<=back;i++) {
                cout << a[i];
                if(i!=back) cout << ',';
            }
            cout << "]\n";
        }
        delete(a);
    }
}