#include <iostream>
#include <string>
using namespace std;
string ss[9];
int s[9][9];
bool flg=false;

void bt(int a);

int main(){
    //for(int i=0;i<9;i++) cin >> ss[i];
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) cin >> s[i][j];
    bt(0);
}

void bt(int a) {
    if(a==81) {
        //for(int i=0;i<81;i++) if(s[i/9][i%9]==0) return;
        for(int i=0;i<81;i++) {
            cout << s[i/9][i%9] << ' ';
            if(i%9==8) cout << '\n';
        }
        flg=true;
        return;
    }
    //for(int i=a;i<81;i++) {
        int r=a/9; int c=a%9;
        //cout << "S " << a << ' ' << i << ' ' << r << ' ' << c << ' ' << s[r][c] << '\n';
        if(s[r][c]!=0) {bt(a+1); return;} //continue;
            bool k[10]={};
            for(int j=0;j<9;j++) {
                //cout << j << ' ' << c << ' ' << s[j][c] << '\n';
                k[s[j][c]]=true;
                k[s[r][j]]=true;
            }
            for(int m=0;m<3;m++) for(int n=0;n<3;n++) {
                //cout << "r: " << r << ' ' << (r/3)*3+m << " c: " << c << ' ' << (c/3)*3+n << ' ' << s[(r/3)*3+m][(c/3)*3+n] << '\n';
                k[s[(r/3)*3+m][(c/3)*3+n]]=true;
            }
            for(int m=1;m<=9;m++) {
                if(!k[m]) {
                    s[r][c]=m;
                    bt(a+1);
                    s[r][c]=0;
                    if(flg) return;
                }
        }
    //}
    if(flg) return;
}