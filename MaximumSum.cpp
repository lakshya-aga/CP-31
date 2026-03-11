#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

typedef long long ll;
using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        int n, k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = n-k;
        ll sum = accumulate(arr.begin(), arr.begin() + (n-k), 0LL);
        ll ans = sum;
        while(right<n)
        {
            sum = sum - arr[left] - arr[left+1] + arr[right];
            ans = max(ans, sum);
            left+=2;
            right++;
            
        }

        cout<<ans<<endl;
        
    }
    return 0;
}