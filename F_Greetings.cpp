#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    typedef tree<long long, 
                 null_type, 
                 less<long long>, 
                 rb_tree_tag, 
                 tree_order_statistics_node_update> 
    ordered_set;

    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<pair<long long, long long>> arr;
        ordered_set sorted_b;
        for(long long i=0; i<n; i++){
            long long a, b;
            cin>>a;
            cin>>b;
            arr.push_back({a, b});
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for(long long i=0; i<n; i++){
            sorted_b.insert(arr[i].second);
            ans+= i - sorted_b.order_of_key(arr[i].second);
        }
        cout<<ans<<endl;
    }

    

    return 0;
}