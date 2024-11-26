#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input;
    int sum=0, temp=0, num=0;
    bool minus_flag = false;
    cin >> input;
    for(int i=0;i<input.length();i++){
        if(isdigit(input[i])) {
            num*=10;
            num+=input[i]-'0';
        } // num에 숫자 기록
        else if(input[i]=='+') {
            temp+=num;
            num=0;
        } // 덧셈
        else if(input[i]=='-') {
            temp+=num;
            if(!minus_flag) { sum+=temp; minus_flag=true; }
            else sum-=temp;
            temp=0; 
            num=0;
        }
    }
    temp+=num;
    if(minus_flag) sum-=temp;
    else sum+=temp;
    cout << sum;
}