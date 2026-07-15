#include <iostream>
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
    long long x, y, z;
    cin>>x>>y;
    z = x;
    if(x!=y)
    z = abs(x-y);
    vector<long long> arr(n, 0);
    for(auto &i: arr) cin>>i;
    
    for(long long i=0; i<n; i++){
        long long diff = abs(i+1 - arr[i]);
        // cout<<diff<<" ";

        if(diff%gcd(x,y) == 0)
        continue;
        else{
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