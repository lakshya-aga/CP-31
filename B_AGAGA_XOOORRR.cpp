#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n, 0);
        for(long long i=0; i<n; i++){
            cin>>arr[i];
        }
        vector<long long> pref(n, 0);
        inclusive_scan(arr.begin(), arr.end(), pref.begin(), [](long long a, long long b){return a ^ b;});
        reverse(arr.begin(), arr.end());
        
        vector<long long> suff(n, 0);
        inclusive_scan(arr.begin(), arr.end(), suff.begin(), [](long long a, long long b){return a ^ b;});
        reverse(arr.begin(), arr.end());

        // Forgot to reverse and lost 20 minutes debugging logic
        reverse(suff.begin(), suff.end());

        auto total_xor = pref[n-1];
        
        // if(total_xor == 0){
        //     cout<<"YES"<<endl;
        //     continue;
        // }

        bool ans = total_xor == 0;
        for(long long i=0; i<n-1; i++){
            if(total_xor==pref[i])
            for(long long j=i+1; j<n; j++){
                if(suff[j]==pref[i]){
                    // cout<<"YES"<<endl;
                    ans = true;
                    break;
                }
            }
            if(ans) break;
        }
        if(ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
// 1     1  1 