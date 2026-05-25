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
        long long temp;
        cin>>n>>temp;
        vector<long long> arr(n);
        vector<long long> brr(n);
        for(long long i=1; i<n; i++){
            cin>>arr[i];
        }
        arr[0] = 1;
        for(long long i=0; i<n; i++){
            cin>>brr[i];
        }
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        long long b_curr = 0;
        long long a_curr = 0;
        long long ops = 0;
        for(long long i=0; i<n; i++){
            // cout<<arr[i]<<", "<<brr[i]<<endl;
            if(arr[a_curr]>=brr[b_curr]){
                ops++;
                b_curr++;
            }
            else
            {
                a_curr++;
                b_curr++;
            }
            // cout<<a_curr<<", "<<b_curr<<endl;
        }
        cout<<ops<<endl;
    }

    return 0;
}