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
        for(long long i=0; i<n; i++){
            cin>>arr[i];
        }
        long long curr_sum = 0;
        long long prev = arr[0];
        for(long long i=0; i<n; i++){
            long long idx = i+1;

            if(i==0){
                cout<<arr[i]<<" ";
                curr_sum+=arr[i];
                prev = arr[i];
                continue;
            }
            if(arr[i]>=prev){
                cout<<prev<<" ";
                curr_sum+=arr[i];

            }
            else{
                long long ans = 1;
                long long high = prev;
                long long low = 1;
                while(high>=low){
                    long long curr = (high+low)/2;
                    long long leftover = curr_sum - curr * i;
                    // cout<<"______"<<endl;
                    // cout<<i<<endl;
                    // cout<<curr<<endl;
                    // cout<<curr_sum<<endl;
                    if(leftover + arr[i] >= curr){
                        low = curr + 1;
                        ans = max(ans, curr);
                    }
                    else{
                        high = curr - 1;
                    }
                }

                cout<<ans<<" ";
                prev = ans;
                curr_sum+=arr[i];

            }
            
            
        }
        cout<<endl;
    }

    return 0;
}