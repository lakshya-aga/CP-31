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

    long long t = 1;
    while(t--){
        long long n;
        cin>>n; // 3
        vector arr(n, 0); // 3 2 1
        vector unsorted(0, 0);
        unsorted.reserve(n);
        for(auto &i: arr) cin>>i;
        
        vector arr_copy = arr;

        sort(arr.begin(), arr.end());
        long long curr=0;
        // unordered_map<long long, long long> mapping;
        // for(auto i: arr_copy){
        //     mapping[i] = curr++;
        // }

        long long min_idx = n-1;
        long long max_idx = 0;

        for(long long i=0; i<n; i++){
            if(arr_copy[i]!=arr[i])
            min_idx = min(i, min_idx);

            if(arr_copy[i]!=arr[i])
            max_idx = max(i, max_idx);
        }

        reverse(arr_copy.begin()+min_idx, arr_copy.begin()+max_idx+1);

        for(long long i=0; i<n; i++){
            if(arr_copy[i]!=arr[i])
            {
                cout<<"no"<<endl;
                return 0;
            }
        }
        if(min_idx>max_idx){ // no change required
            min_idx = max_idx;
        }
        cout<<"yes"<<endl;
        cout<<min_idx+1<<" "<<max_idx+1<<endl;
    }

    return 0;
}