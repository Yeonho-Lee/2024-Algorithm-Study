#include <cstdio>
#include <queue>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        std::queue<int> q;
        int a[11]={}, b[102]={}, n, u, temp=0, cnt=0;
        scanf("%d %d", &n, &u);

        // input
        for(int i=0;i<n;i++) { scanf("%d", &b[i]); a[b[i]]++; }

        // 출력해야 할 문서의 중요도 설정
        temp = b[u];
        b[u] += 10;
        for(int i=0;i<n;i++) q.push(b[i]);

        int i=9;
        // queue에서 10보다 큰 값 나올 때까지 반복
        while(1) {
            if(a[i]==0) { i--; continue; }
            if(i==temp && q.front()>10) { printf("%d\n", cnt+1); break; }
            if(q.front()%10==i) { q.pop(); cnt++; a[i]--; }
            else { q.push(q.front()); q.pop(); }
        }
    }
}