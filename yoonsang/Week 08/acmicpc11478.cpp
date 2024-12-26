#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
string temp, slice;
unordered_set<string> m;
int cnt=0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> temp;
    for(int i=1;i<=temp.length();i++){
        for(int j=0;j<=temp.length()-i;j++){
            m.insert(temp.substr(j,i));
        }
    }
    cout << m.size();
}

// 자료구조(해시를 사용한 집합과 맵) 연습1: 문자열 집합(S3)