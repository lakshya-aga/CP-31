#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

long long INTMAX = 1e8;

void solve(){
    long long n;
    cin>>n;
    vector arr(n, 0);
    for(auto &i: arr)
    cin>>i;

    auto brr = arr;
    auto crr = arr;
    for(long long i=0; i<n; i++){
        if(arr[i]!=1) brr[i] = -1; else brr[i] = 1;
        if(arr[i]!=3) crr[i] = 1; else crr[i] = -1;
    }
    inclusive_scan(brr.begin(), brr.end(), brr.begin());
    inclusive_scan(crr.begin(), crr.end(), crr.begin());
    crr[crr.size()-1] = (-INTMAX);
    auto c_max = crr;
    exclusive_scan(crr.rbegin(), crr.rend(), c_max.rbegin(), -INTMAX, [](long long x, long long y){
        return max(x,y);
    });

    
    // for(auto i: brr) cout<<i<<" "; cout<<endl;
    // for(auto i: crr) cout<<i<<" "; cout<<endl;
    // for(auto i: c_max) cout<<i<<" "; cout<<endl;
    

    for(long long i=0; i<n-1; i++){
        if(brr[i]>=0 && c_max[i]-crr[i]>=0)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}