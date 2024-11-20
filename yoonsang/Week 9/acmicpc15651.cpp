#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
void backtracking(int d){
    if(d==m) {
        for(int i=0;i<m;i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++) {
        v.push_back(i);
        backtracking(d+1);
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    backtracking(0);
}