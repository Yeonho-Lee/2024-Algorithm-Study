#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,arr[9];
bool used[9];
vector<int> v;
void backtracking(int d, int p){
    if(d==m) {
        for(int i=0;i<m;i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0;i<n;i++) {
        if(!used[i]) {
            v.push_back(arr[i]);
            used[i]=true;
            backtracking(d+1, i);
            v.pop_back();
            used[i]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    backtracking(0, 1);
}