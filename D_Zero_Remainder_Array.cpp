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
        long long n, k;
        cin>>n>>k;
        long long ans = 0;
        vector<long long> arr(n);
        int max_freq = 1;
        int max_key = (k - (arr[0] % k))%k;
        unordered_map<long long, long long> freq;
        for(long long i=0; i<n; i++){
            cin>>arr[i];
            long long moves = (k - (arr[i] % k))%k;
            // cout<<arr[i]<<":"<<moves<<" ";
            
            freq[moves]++;
            if(moves!=0 && freq[moves]>max_freq || (freq[moves]==max_freq && moves>max_key)){
                max_freq = freq[moves];
                max_key = moves;
            }
            // cout<<moves<<endl;    
        }
        ans = max_key + (max_freq-1)*k;

        if(ans>=1){
            ans++;
        }
        cout<<ans<<endl;


    }

    return 0;
}   