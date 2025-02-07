#include <iostream>
#include <vector>
using namespace std;
long long n,r,q,a,b;

struct Tree{
    int parent=-1, size=1;
    vector<int> nodes;
} tree[100001];

int maketree(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> r >> q;
    for(int i=0;i<n-1;i++) {
        cin >> a >> b;
        tree[a].nodes.push_back(b);
        tree[b].nodes.push_back(a);
    }
    maketree(r);
    for(int i=0;i<q;i++) {
        cin >> a;
        cout << tree[a].size << '\n';
    }
}

int maketree(int node){
    if(node!=r && tree[node].nodes.size()==1) return 1;
    for(auto i:tree[node].nodes) {
        if(tree[node].parent==i) continue;
        tree[i].parent=node;
        tree[node].size+=maketree(i);
    }
    return tree[node].size;
}