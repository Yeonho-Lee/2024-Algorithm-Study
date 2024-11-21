#include <iostream>
#include <algorithm>
#include <cmath>
#define parent(i) i/2
#define leftchild(i) i*2
#define rightchild(i) i*2+1
#define swap(a,b) {int t=a; a=b; b=t;}
using namespace std;
int n,temp,a[100002]={-1,},sizea=0;
void maxheap(int n, int num, bool insert){
    if(insert){
        for(int i=1;i<=log2(n);i++){
            int init=num, p=parent(num);
            if(a[init] > a[p]) init=p;
            if(init!=num) { swap(a[init], a[num]); num=init; }
            else break;
        }
        for(int i=1;i<=log2(n);i++){
            int maximum=num, l=leftchild(num), r=rightchild(num);
            if(l <= n && a[maximum] < a[l]) maximum=l;
            if(r <= n && a[maximum] < a[r]) maximum=r;
            if(maximum!=num){ swap(a[maximum], a[num]); num=maximum; }
            else break;
        }
    } else {
        for(int i=1;i<=log2(n);i++){
            int maximum=num, l=leftchild(num), r=rightchild(num);
            if(l <= n && a[maximum] < a[l]) maximum=l;
            if(r <= n && a[maximum] < a[r]) maximum=r;
            if(maximum!=num){ swap(a[maximum], a[num]); num=maximum; }
            else break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        cin >> temp;
        if(temp==0) { 
            if(sizea) { 
                cout << a[1] << '\n';
                swap(a[sizea], a[1]);
                sizea=max(sizea-1,0);
                maxheap(sizea, 1, false);
            }
            else cout << "0\n";
        }
        else {
            sizea++;
            a[sizea]=temp;
            maxheap(sizea, sizea, true);
        }
    }
}

// 자료구조 미사용, 직접 heap 구현