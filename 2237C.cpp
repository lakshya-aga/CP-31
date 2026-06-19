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
        vector<long long> arr(n);
        for(auto &i: arr) cin>>i;
        long long ans = arr[0];
        for(long long i=1; i<n; i++){
            if(ans>arr[i]){
                ans+=arr[i];
            }
            else{
                ans = arr[i];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}