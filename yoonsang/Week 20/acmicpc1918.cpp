#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
string s;

string a(string tot){
    stack<char> st, oper;
    string temp;
    int n, num=0;
    while(!tot.empty()) {
        if(tot[0]=='(') { // 괄호가 있으면 따로 처리
            for(int i=1;i<tot.size();i++) {
                if(tot[i]==')' && num==0) {n=i; break; }
                if(tot[i]=='(') {num++;}
                if(tot[i]==')' && num) {num--;}
            }
            temp = a(tot.substr(1, n-1));
            for(int i=0;i<temp.size();i++) st.push(temp[i]);
            if(tot.length()>=n+2) tot = tot.substr(n+1);
            else tot = "";
        } else if(tot[0]>=65) { // 대문자일 때
            st.push(tot[0]);
            tot.erase(tot.begin());
        } else if(tot[0]=='*' || tot[0]=='/') { // * or /
            if(oper.empty() || (!oper.empty() && (oper.top()=='+' || oper.top()=='-'))) {
                oper.push(tot[0]);
                tot.erase(tot.begin());
            } else if(!oper.empty() && (oper.top()=='*' || oper.top()=='/')) {
                while(!oper.empty() && (oper.top()=='*' || oper.top()=='/')) {
                    st.push(oper.top());
                    oper.pop();
                }
                oper.push(tot[0]);
                tot.erase(tot.begin());
            }
        } else if(tot[0]=='+' || tot[0]=='-') { // + or -
            if(oper.empty()) {
                oper.push(tot[0]);
                tot.erase(tot.begin());
            } else if(!oper.empty()) {
                while(!oper.empty()) {
                    st.push(oper.top());
                    oper.pop();
                }
                oper.push(tot[0]);
                tot.erase(tot.begin());
            }
        }
    }
    while(!oper.empty()) {
        st.push(oper.top());
        oper.pop();
    }
    temp="";
    while(!st.empty()) {
        temp+=st.top();
        st.pop();
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    cout << a(s);
}