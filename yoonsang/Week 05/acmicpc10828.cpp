#include <stdio.h>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <cstring>

int main(){
    std::stack<int> st;
    int n;
    scanf("%d", &n);
    std::cin.ignore();
    for(int i=0;i<n;i++){
        char a[13]="";
        std::cin.getline(a, 12);
        if(a[0]=='t') {
            if(st.empty()) printf("-1\n");
            else printf("%d\n", st.top());
        }
        else if(a[0]=='e') printf("%d\n", st.empty());
        else if(a[0]=='s') printf("%d\n", st.size());
        else if(a[1]=='o') { 
            if(st.empty()) printf("-1\n");
            else { printf("%d\n", st.top()); st.pop(); }
        }
        else {
            int push=0;
            for(int i=5;i<12;i++){
                if(isdigit(a[i])==0) break;
                else { push*=10; push+=(a[i]-'0'); }
            }
            st.push(push);
            // atoi가 안 먹힘 왜지 문자열도 잘 잘라냈는데
        }
    }
}