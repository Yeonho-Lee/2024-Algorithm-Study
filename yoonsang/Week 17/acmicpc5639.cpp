#include <iostream>
using namespace std;

struct trees {
	int parent=-1;
	int leftChild=-1;
	int rightChild=-1;
} tree[1000001];
void back(int m){
	if(tree[m].leftChild!=-1) back(tree[m].leftChild);
	if(tree[m].rightChild!=-1) back(tree[m].rightChild);
	cout << m << '\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int temp, curr, top, p;
	cin >> temp;
	top=temp;
	while(1){
		cin >> temp;
		if(cin.eof()) break;
		p=top;
		
		if(top<temp){
			curr = tree[top].rightChild;
			while(curr!=-1) {
				p=curr;
				if(curr<temp) curr = tree[curr].rightChild;
				else curr = tree[curr].leftChild;
			}
			// tree[6] = {parent=4, left=7, right=9}
			// tree[4] = {...			    right=6}
			// tree[7] = {parent=6, ...			   }
			// tree[9] = {parent=6, ...			   }
			if(p<temp) tree[p].rightChild = temp;
			else tree[p].leftChild = temp;
			tree[temp].parent = p;
		} else {
			curr = tree[top].leftChild;
			while(curr!=-1) {
				p=curr;
				if(curr<temp) curr = tree[curr].rightChild;
				else curr = tree[curr].leftChild;
			}
			if(p<temp) tree[p].rightChild = temp;
			else tree[p].leftChild = temp;
			tree[temp].parent = p;
		}
	}
	back(top);
}