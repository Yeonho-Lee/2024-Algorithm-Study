#include <iostream>
using namespace std;
int n,m,arr[500001]={},a,b;

int unions(int p, int q);
int find(int p);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) arr[i]=i;
    for(int i=1;i<=m;i++) {
        cin >> a >> b;
        if(unions(a, b)==1) { cout << i; return 0; }
    }
    cout << 0;
}

int unions(int p, int q) {
    p=find(p);
    q=find(q);

    if(p==q) return 1;
    if(p<q) arr[q]=p;
    else arr[p]=q;
    return 0;
}

int find(int p) {
    if(arr[p]==p) return p;
    else return arr[p]=find(arr[p]);
}