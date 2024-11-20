#include <iostream>
#include <vector>
using namespace std;
int n,m,arr[9];
bool used[9]={};
void backtracking(int d){
    if(d==m) {
        for(int i=0;i<m;i++) cout << arr[i] << ' ';
        cout << '\n';
    }
    for(int i=1;i<=n;i++) {
        if(!used[i]) {
            arr[d]=i;
            used[i]=true;
            backtracking(d+1);
            used[i]=false;
        }
    }
} // n: 최댓값, m: 길이, d: 깊이
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    backtracking(0);
}