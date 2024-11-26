#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define swap(a,b) {int t=a; a=b; b=t;}
#define parents(a) (a-1)/2
#define leftchild(a) a*2+1
#define rightchild(a) a*2+2
int a[1000001];
int max=-99999999, maxidx;

void maxhip(int a[], size_t size, int n){
    // max hip을 만들어요
    // max hip이란? 모든 부분 트리에서 부모 노드의 값이 모든 자식 노드의 값보다 큰 트리
    for (int j=0;j<log2(n)+1;j++){ for (int i=n-1;i>0;){
        // [i-1] == a[leftchild(parents(i))]이나 이해의 편의를 위해 아래와 같이 작성
        // heap sort 처음이라 a[i-1] 하면 나중에 못알아먹고 엥 이게 뭐지 하고 있을 가능성이 아주아주아주 큼
        if(i%2==0){
            if((a[leftchild(parents(i))] < a[i]) && (a[parents(i)] < a[i])){
                swap(a[parents(i)], a[i])
            } else if(a[leftchild(parents(i))] > a[i] && a[parents(i)] < a[leftchild(parents(i))]) {
                swap(a[parents(i)], a[leftchild(parents(i))])
            }
            i-=2;
        } else {
            if(a[parents(i)] < a[i]) swap(a[parents(i)], a[i])
            i--;
        }
    }}  
}

void heapsort(int a[], size_t size, int n){
    // 이제 정렬해요
    // max hip으로 정렬해놔서 루트 노드가 제일 크니까 걔 맨 밑으로 내려보내고
    // 자식 둘 중 본인보다 크고 다른 자식보다 큰 노드랑 위치 바꿔가면서 max hip 구조는 유지시키면 됨
    for(int i=0;i<n-1;i++){
        swap(a[0], a[n-i-1])
        int crt=0;
        while(1){
            if(leftchild(crt)>=n-i-1) { break; } 
            if(rightchild(crt)>=n-i-1) {
                if(a[leftchild(crt)] > a[crt]) swap(a[leftchild(crt)], a[crt])
                break;
            }
            if(a[leftchild(crt)] > a[rightchild(crt)]){ 
                if(a[leftchild(crt)] > a[crt]) {
                    swap(a[crt], a[leftchild(crt)]) 
                    crt=leftchild(crt);
                } else { break; }
            } else {
                if(a[rightchild(crt)] > a[crt]) {
                    swap(a[crt], a[rightchild(crt)])
                    crt=rightchild(crt);
                } else { break; }
            }
        }
    }
}

int main(){
    // 일단 배열을 입력 최솟값보다 더 작은 값으로 만들어요
    std::fill_n(a, 1000000, -1000001);
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){ scanf("%d", &a[i]); }
    maxhip(a, n, n);
    heapsort(a, n, n);
    // 정렬 완료! 시간복잡도 O(n log n)
    for(int i=0;i<n;i++) printf("%d\n", a[i]);
}

// 2751번의 다른 풀이
// 100만개 집어넣어도 0.06초면 정렬 완료라는게 신기함
// O(n) 가진 무지막지한 정렬 방법 있는거 아니면 앞으로 이것만 주구장창 돌려 쓸 것 같은데
// Merge Sort같은 다른 방법이랑 비교해서 어느 상황에 어떤 Sort가 더 효율적인지는 따져봐야 할 것 같음
// 효율 차이가 크지 않다면 heap sort만 주구장창 돌려먹어도 될 듯