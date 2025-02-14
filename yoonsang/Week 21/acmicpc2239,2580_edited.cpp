#include <iostream>
#include <string>
#include <vector>
using namespace std;
string ss[9];
int s[9][9];
bool flg=false;

void bt(int a);
vector<int> isValid(int r, int c);

int main(){
    for(int i=0;i<9;i++) cin >> ss[i];
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) s[i][j]=ss[i][j]-'0';
    bt(0);
    for(int i=0;i<81;i++) {
        cout << s[i/9][i%9];
        if(i%9==8) cout << '\n';
    }
}

void bt(int a) {
    if(a==81) {
        flg=true;
        return;
    }
    int r=a/9; int c=a%9;
    if(s[r][c]!=0) { bt(a+1); return; }
    for(auto i:isValid(r, c)) { // return vector<int> type
        s[r][c]=i;
        bt(a+1);
        if(flg) return;
        s[r][c]=0;
    }
}

vector<int> isValid(int r, int c){
    vector<int> validvector;
    bool k[10]={};
    for(int j=0;j<9;j++) {
        k[s[j][c]]=true;
        k[s[r][j]]=true;
    }
    for(int m=0;m<3;m++) for(int n=0;n<3;n++) {
        k[s[(r/3)*3+m][(c/3)*3+n]]=true;
    }
    for(int i=1;i<=9;i++) {
        if(!k[i]) validvector.push_back(i);
    }
    return validvector;
}