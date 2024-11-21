#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
void backtracking(int d, int p){
    if(d==m) {
        for(int i=0;i<m;i++) cout << v[i] << ' ';
        cout << '\n';
        //return; 이걸 안 달아도 동작한다..!! i=p에서부터 시작하니 n을 넘어가면 종료되기 때문인듯...
    }
    for(int i=p;i<=n;i++) {
        v.push_back(i);
        backtracking(d+1, i+1);
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    backtracking(0, 1);
}
// 백트래킹 어렵다..