#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
void post(int s, int e){
    if(s>=e) return;
    if(s==e-1){
        cout << v[s] << '\n';
        return;
    }
    
    int index = s+1;
    while(index<e){
        if(v[s] < v[index]) break;
        index++;
    }
    
    post(s+1, index);
    post(index, e);
    cout << v[s] << '\n';
}
int main(){
    int a;
    while(cin >> a){
        v.push_back(a);
    }
    post(0, v.size());
    return 0;
}