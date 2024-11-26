#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string temp, arr[100001];
unordered_map<string, int> m;
int n,k;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> temp;
        m.insert({temp, i});
        arr[i] = temp;
    }
    while(k--) {
        cin >> temp;
        if(isdigit(temp[0])) { // 숫자면
            cout << arr[stoi(temp)] << '\n';
        } else { // 글자면
            cout << m.find(temp)->second << '\n';
        }
    }
}

// std::endl 때문에 자꾸 TLE 떠서 애먹음
// std::endl는 생각보다 많이 느리다...