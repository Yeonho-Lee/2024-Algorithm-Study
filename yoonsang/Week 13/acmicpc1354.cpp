#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;
long long n,p,q,x,y;
unordered_map<long long, long long> m;
void re(long long nn){
	if(nn==0) return;
	long long i=nn/p-x, j=nn/q-y;
	if(i>0 && m.find(i)==m.end()) re(i);
	if(j>0 && m.find(j)==m.end()) re(j);
	m.insert({nn, (i<0 ? 1 : m.find(i)->second) + (j<0 ? 1 : m.find(j)->second)});
}
int main(){
	cin >> n >> p >> q >> x >> y;
	m.insert({0,1});
	re(n);
	cout << m.find(n)->second;
}