#include <iostream>
using namespace std;
int n,m,arr[51],party[51][52],truth,pnum,participants,cnt=0,temp;

int find(int a) {
	if (a==arr[a]) return a;
	return arr[a]=find(arr[a]);
}

void unions(int a, int b) {
	a=find(a);
	b=find(b);
	if (a==b) return;

    if(a<b) arr[b]=a;
    else arr[a]=b;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> truth;
	for (int i=1;i<=n;i++) arr[i]=i;
	for (int i=0;i<truth;i++) {
        cin >> temp;
        arr[temp]=0;
    }
	for (int i=0;i<m;i++) {
		cin >> party[i][0];
		for (int j=1;j<=party[i][0];j++) {
            cin >> party[i][j];
            if(j>=2) unions(arr[party[i][j-1]], arr[party[i][j]]);
        }
	}
	for (int i=0;i<m;i++) {
		bool isValid = true;
		for (int j=0;j<truth;j++) {
			if (find(arr[party[i][1]])==0) {
				isValid = false;
				break;
			}
		}
		if (isValid) cnt++;
	}
	cout << cnt;
}