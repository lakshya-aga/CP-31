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
        long long n,a,b;
        cin>>n>>a>>b;
        vector<long long> arr(n);
        for(long long i=0; i<n; i++){
            cin>>arr[i];
        }
        long long position = 0;
        long long ans = 0;
        for(long long i=0; i<n; i++){
            ans+=(arr[i]-position)*b; // conquer cost
            if(a<=(n-i-1)*b){ // determine if to move
                ans+=(arr[i]-position)*a;
                position = arr[i]; // move cost
            }
            // cout<<ans<<" ";
        }
        // cout<<endl;
        cout<<ans<<endl;

        

    }

    return 0;
}