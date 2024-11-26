#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int n,temp;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        cin >> temp;
        if(temp==0){
            if(q.empty()) cout << "0\n";
            else { cout << q.top() << '\n'; q.pop(); }
        } else {
            q.push(temp);
        }
    }
}

// 자료구조(우선순위 큐) 사용