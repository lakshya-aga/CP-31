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
    long long ans = 0;
    for(long long i=1; i<=n; i++){
        ans+=((n/i )* (n/i));
        // cout<<i<<": "<<((n/i) * (n/i))<<endl;
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // your code here
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}