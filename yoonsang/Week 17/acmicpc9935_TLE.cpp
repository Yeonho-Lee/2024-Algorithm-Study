#include <iostream>
#include <string>
using namespace std;
string in, check;
int ss;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> in >> check;
	ss=in.size()-check.size();
	for(int i=0;i<=ss;i++){
		if(i<0) continue;
		if(in.substr(i, check.size())==check) {
			in = in.substr(0,i)+in.substr(i+check.size());
			i-=check.size();
		}
		ss=in.size()<check.size()?0:in.size()-check.size();	
	}
	cout << (in.size()>0?in:"FRULA");
}