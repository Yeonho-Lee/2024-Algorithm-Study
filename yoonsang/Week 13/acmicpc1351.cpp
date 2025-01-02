#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;
long long n,p,q;
unordered_map<long long, long long> m;
void re(long long nn){
	if(nn==0) return;
	long long i=nn/p, j=nn/q;
	if(m.find(i)==m.end()) re(i);
	if(m.find(j)==m.end()) re(j);
	m.insert({nn, m.find(i)->second+m.find(j)->second});
}
int main(){
	cin >> n >> p >> q;
	m.insert({0,1});
	re(n);
	cout << m.find(n)->second;
}