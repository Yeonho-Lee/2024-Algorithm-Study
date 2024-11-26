#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
struct aa{
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, temp;
    priority_queue<int, vector<int>, aa> q;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> temp;
        if(temp==0){
            if(q.empty()){
                cout << 0 << '\n';
                continue;
            }
            cout << q.top() << '\n';
            q.pop();
        }
        else q.push(temp);
    }
    return 0;
}
// 이것뭐에요?