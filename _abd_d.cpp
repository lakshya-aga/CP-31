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
    long long m;
    cin>>m;
    vector<long long> arr(n,0);
    for(auto &i: arr) cin>>i;
    
    vector<long long> brr(m,0);
    for(auto &i: brr) cin>>i;

    // brr.push_back(-1);
    long long curr_ptr = 0;
    long long curr_sum = 0;
    long long curr_max = 0;
    long long curr_min = 0;
    sort(brr.begin(), brr.end());
    for(long long i=0; i<n; i++){
        curr_sum = curr_sum+arr[i];
        curr_max = curr_max+arr[i];
        curr_min = curr_min+arr[i];
        if(curr_ptr<m && brr[curr_ptr]-1==i){
            curr_max = max(curr_max, -curr_min);
            curr_min = min(-curr_max, curr_min);
            curr_ptr++;
        }
        // cout<<curr_max<<" "<<curr_min<<endl;
    }
    cout<<curr_max<<endl;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}