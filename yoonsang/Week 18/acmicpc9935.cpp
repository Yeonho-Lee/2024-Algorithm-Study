#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
string in, check, ifcheck;
stack<char> st;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> in >> check;
	reverse(check.begin(), check.end());
	for(int i=0;i<in.length();i++) {
		if(in[i]==check[0] && st.size()>=check.length()-1){
			ifcheck=check[0];
			for(int j=0;j<check.length()-1;j++){
				ifcheck+=st.top();
				st.pop();
			}
			if(check.compare(ifcheck)!=0) {
				reverse(ifcheck.begin(), ifcheck.end());
				for(int j=0;j<ifcheck.length();j++) {
					st.push(ifcheck[j]);
				}
			}
		} else {
			st.push(in[i]);
		}
	}
	int k=st.size();
	in="";
	for(int i=0;i<k;i++) {
		in+=st.top();
		st.pop();
	}
	reverse(in.begin(), in.end());
	cout << (in.size()>0?in:"FRULA");
}