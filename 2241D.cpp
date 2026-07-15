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
    vector<long long> arr(n);
    vector<long long> brr(n);
    vector<long long> crr(n, 0 );

    for(auto &i: arr) cin>>i;
    for(auto &i: brr) cin>>i;

    long long cum_diff = 0;
    bool flag = true;
    for(long long i=0; i<n; i++){
        
        crr[i] = i>0? crr[i-1] + (brr[i]-arr[i]): (brr[i]-arr[i]);
        
        if(crr[i]<0){
            flag = false;
        }
        // cout<<crr[i]<<" ";

    }
    // cout<<"\n";
    if(flag)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
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