#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
string temp1, temp2, temp3;
vector<int> graph[27];
void front(int m){
    cout << (char)(m+'A');
    for(auto i:graph[m]){
        if(i==-1) continue;
        front(i);
    }
}
void mid(int m){
    if(graph[m].front()!=-1) mid(graph[m].front());
    cout << (char)(m+'A');
    if(graph[m].back()!=-1) mid(graph[m].back());
}
void back(int m){
    for(auto i:graph[m]){
        if(i==-1) continue;
        back(i);
        cout << (char)(i+'A');
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> temp1 >> temp2 >> temp3;
        if(temp2!=".") graph[temp1[0]-'A'].push_back(temp2[0]-'A');
        else graph[temp1[0]-'A'].push_back(-1);
        if(temp3!=".") graph[temp1[0]-'A'].push_back(temp3[0]-'A');\
        else graph[temp1[0]-'A'].push_back(-1);
    }
    front(0);
    cout << '\n';
    mid(0);
    cout << '\n';
    back(0);
    cout << "A";
}