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
    long long n, k;
    cin>>n>>k;
    vector arr(n, 0);
    // vector arr_copy(n, 0);
    for(auto &i: arr){
        cin>>i;
    }
    long long high = accumulate(arr.begin(), arr.end(), -1, [](long long x, long long y){return max(x,y);});
    auto low = high;
    // cout<<low<<endl;
    high = high+k;
    auto mid = (high+low)/2;
    auto ans = low;
    while(high>=low){
        mid = (high+low)/2;
        // cout<<mid<<endl;
        bool flag = false;
        for(long long i=0; i<n; i++){
            long long req = 0;
            for(long long j=i; j<n; j++){
                req+=max(0ll, (mid - arr[j]) - (j-i)); // 1 1 
                if(j==n-1 && mid - arr[j] - (j-i) > 0)
                req = 1e9;
                // cout<<req<<" ";
                if(req>k){
                    break;
                }
                if(mid - arr[j] - (j-i) <= 0)
                {
                    flag = true;
                    break;
                }
            }
            // cout<<endl;
            if(flag) break;
        }
        if(flag){
            ans = max(ans, mid);
            low = mid+1;
        }
        else{
            // ans = max(ans, mid);
            high = mid-1;
        }
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