#include <iostream>
using namespace std;
long long n, cnt=0;
int a[16]={};
bool visited[16]={};
void nqueen(int depth, int pre){
	if(depth==n){ cnt++; return; }
	for(int i=0;i<n;i++){
		bool flg=false;
		for(int j=0;j<depth;j++) {
			if(abs(a[j]-i)==depth-j) { flg=true; break; }
		}
		if(!visited[i] && !flg) {
			visited[i]=true;
			a[depth]=i;
			nqueen(depth+1, i);
			visited[i]=false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	nqueen(0, -2);
	cout << cnt;
}