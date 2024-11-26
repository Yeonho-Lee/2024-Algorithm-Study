#include <cstdio>
#include <queue>
#include <cstring>
int main(){
    std::queue<int> q;
    int n,num;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char a[7];
        scanf("%s", a);
        if(strcmp(a,"size")==0) printf("%d\n", q.size());
        if(strcmp(a,"empty")==0) printf("%d\n", q.empty());
        if(strcmp(a,"front")==0) { if(q.empty()) printf("-1\n"); else printf("%d\n", q.front()); }
        if(strcmp(a,"back")==0) { if(q.empty()) printf("-1\n"); else printf("%d\n", q.back()); }
        if(strcmp(a,"pop")==0) { if(q.empty()) printf("-1\n"); else { printf("%d\n", q.front()); q.pop(); } }
        if(strcmp(a,"push")==0) { scanf("%d", &num); q.push(num); }
    }
}