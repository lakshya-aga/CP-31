#include <iostream>
#include <bit>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(auto &i: arr) cin>>i;
    auto cum_max = arr[0];
    int ans = 0;
    for(long long i=0; i<n; i++){
        unsigned long long diff = max(cum_max - arr[i], 0ll);
        cum_max = max(arr[i], cum_max);
        // cout<<31 - __builtin_clz(diff)<<" ";
        // cout<<(diff)<<endl;
        ans = max(bit_width(diff), ans);
    }
    cout<<ans<<"\n";
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