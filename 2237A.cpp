#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);

        for(auto& i: arr) cin>>i;
        long long ans = 0;
        auto curr_min = arr[0];
        for(long long i=0; i<n; i++){
            curr_min = min(curr_min, arr[i]);
            ans+=curr_min;
        }
        cout<<ans<<endl;
    }
    

    return 0;
}