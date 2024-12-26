#include <stdio.h>
#include <iostream>
#include <stack>

int main(void){
    std::stack<int> st;
    int n,sum=0,temp;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp==0) { sum-=st.top(); st.pop(); }
        else {
            st.push(temp);
            sum+=temp;
        }
    }
    printf("%d", sum);
    return 0;
}
// 스택 자료구조를 처음으로 사용해봤습니다