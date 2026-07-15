#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

void solve(){
    long long n, x;
    cin>>n>>x;
    vector<long long> arr(n);
    for(auto &i: arr) cin>>i;

    vector<long long> pref(n);
    sort(arr.begin(), arr.end());
    inclusive_scan(arr.begin(), arr.end(), pref.begin());

    vector<long long> max_buy(n);
    long long ans = 0;
    for(long long i=0; i<n; i++){
        
        max_buy[i] = max(0ll, (x - pref[i] + 1 + i)/ (i + 1));
        ans+=max(0ll, max_buy[i]);
    }
    cout<<ans<<endl;
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