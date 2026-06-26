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
    vector<long long> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    long long ans = 0ll;
    if(arr.back()>0) ans++;
    for(long long i=n-2; i>=0; i--){
        arr[i] = arr[i]+max(0ll, arr[i+1]);
        if(arr[i]>0) ans++;
    }
    cout<<ans<<endl;
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