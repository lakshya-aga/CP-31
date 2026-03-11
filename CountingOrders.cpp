#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

typedef long long ll;
using namespace std;

int main() {
    ll MOD = 1e9 + 7;
    int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<ll> brr(n);
        for(int i=0; i<n; i++) {
            cin>>brr[i];
        }
        sort(brr.begin(), brr.end());   
        
        int a_right = n-1;
        int b_right = n-1;
        ll ans = 1;
        for(int i=n-1; i>=0; i--) {
            ll choices = n - (lower_bound(arr.begin(), arr.end(), brr[i]+1) - arr.begin());

            ans = (ans * max(0ll, (choices - (n - i - 1)))) % MOD;
        }

        cout<<ans<<endl;
    }
    return 0;
}