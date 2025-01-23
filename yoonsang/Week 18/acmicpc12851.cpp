#include <iostream>       // for cin, cout
#include <queue>          // for queue
#include <array>          // for array
#include <algorithm>      // for fill_n
#include <unordered_map>  // for unordered_map
using namespace std;
queue<array<int, 2>> q;
int n,k,road[100001]={}, loc, num;
bool lock=false;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
	if(n>k) { cout << n-k << '\n' << 1; return 0;}
    q.push({n, 1});
	for(int i=0;;i++){
		fill_n(road, 100000, 0);
		while(!q.empty()){
			loc=q.front()[0]; num=q.front()[1]; q.pop();
			if(loc==k) {
				cout << i << '\n' << num;
				return 0;
			}
			if(loc>0) road[loc-1]+=num;
			if(loc<100000) road[loc+1]+=num;
			if(loc<=50000) road[loc*2]+=num;
		}
		for(int i=0;i<100001;i++){
			if(road[i]) q.push({i, road[i]});
		}
	}
}