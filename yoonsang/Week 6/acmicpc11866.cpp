#include <cstdio>
#include <queue>
int main(){
    std::queue<int> q;
    int n,k;
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++) q.push(i);
    printf("<");
    for(int i=0;i<n;i++){
        for(int j=0;j<k-1;j++){
            q.push(q.front());
            q.pop();
        }
        printf("%d",q.front());
        q.pop();
        if(i<n-1) printf(", ");
    }
    printf(">");
}