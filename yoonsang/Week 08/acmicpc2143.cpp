#include <iostream>
#include <set>
#include <map>
using namespace std;
map<long long, long long> asum, bsum;
long long t,n,m,a[1001],b[1001],as[1001],bs[1001],cnt=0,temp;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    cin >> n;
    cin >> a[0]; as[0]=a[0]; asum.insert({as[0], 1});
    for(int i=1;i<n;i++) { cin >> a[i]; as[i]=as[i-1]+a[i]; asum.insert({as[i], 1}); }
    cin >> m;
    cin >> b[0]; bs[0]=b[0]; bsum.insert({bs[0], 1});
    for(int i=1;i<m;i++) { cin >> b[i]; bs[i]=bs[i-1]+b[i]; bsum.insert({bs[i], 1}); }
    for(int i=0;i<n;i++) {
        for(int j=n-1;j>i;j--){
            temp = as[j]-as[i];
            if(asum.find(temp)==asum.end()) asum.insert({temp, 1});
            else asum[temp]++;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=m-1;j>i;j--){
            temp = bs[j]-bs[i];
            if(bsum.find(temp)==bsum.end()) bsum.insert({temp, 1});
            else bsum[temp]++;
        }
    }
    auto b=bsum.end();
    b--;
    for(auto i:asum){
        long long target = t-i.first;
        while((b->first) > target) {
            b--;
            if(b == bsum.begin()) break;
        }
        if((b->first) == target) { 
            cnt+=(i.second) * (b->second); 
            if(b==bsum.begin()) break; 
            b--; }
    }
    cout << cnt;
}

// TLE