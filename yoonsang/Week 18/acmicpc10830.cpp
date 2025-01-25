#include <iostream>
#include <cmath>
using namespace std;
int n, square[40][5][5]={}, lists[38]={}, results[40][5][5], temp;
long long b;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> b;

	// input
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> square[0][i][j];
	
	// 2제곱 이후 행렬곱 미리 계산해두기
	for(int k=1;k<39;k++){
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
			for(int a=0;a<n;a++) square[k][i][j]+=(square[k-1][i][a]*square[k-1][a][j]);
			square[k][i][j]%=1000;
		}
	}

	// b를 2의 거듭제곱 형태로 분해
	int limits=0;
	while(b){
		lists[limits]=(int)log2(b+0.0);
		b-=pow(2, (int)log2(b+0.0));
		limits++;
	}

	// results 초기값 설정
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		results[0][i][j] = square[lists[0]][i][j]%1000;
	}

	// results 계산
	for(int k=1;k<limits;k++){
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
			temp=0;
			for(int a=0;a<n;a++) temp+=(results[k-1][i][a]*square[lists[k]][a][j]);
			results[k][i][j]=temp%1000;
		}
	}

	// 출력
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << results[limits-1][i][j] << ' ';
		}
		cout << '\n';
	}
}