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
    long long n;
    cin>>n;
    vector<long long> arr(n, 0ll);
    for(auto &i: arr) cin>>i;
    auto curr_total = 0ll;
    for(long long i=0; i<n; i++){
        curr_total+=arr[i];
        curr_total = min(curr_total, (long long)1e11);
        if(curr_total<(i+2)*(i+1)/2ll)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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