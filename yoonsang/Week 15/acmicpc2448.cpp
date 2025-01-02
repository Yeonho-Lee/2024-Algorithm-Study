#include <iostream>
#include <cstring>
using namespace std;
bool a[4000][7000]={};
int n;

void fillout(int size, int x, int y){
    if(size==1){
        a[x][y+2]=true;
        a[x+1][y+1]=true;
        a[x+1][y+3]=true;
        for(int i=0;i<5;i++) a[x+2][y+i]=true;
        return;
    }

    fillout(size/2, x+3*size/2, y);
    fillout(size/2, x, y+3*size/2);
    fillout(size/2, x+3*size/2, y+3*size);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    fillout(n/3, 0, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            cout << (a[i][j]==true ? '*' : ' ');
        }
        cout << '\n';
    }
}