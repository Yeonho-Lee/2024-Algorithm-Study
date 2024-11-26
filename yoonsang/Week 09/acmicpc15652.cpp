#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
void backtracking(int d, int p){
    if(d==m) {
        for(int i=0;i<m;i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=p;i<=n;i++) {
        v.push_back(i);
        backtracking(d+1, i);
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; // 4 2
    backtracking(0, 1);
}
// 솔직히 이해 잘 안 됨.. 재귀는 역시 어렵다 비직관적이고