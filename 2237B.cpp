#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
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
        vector<long long> brr(n);
        
        for(auto& i: arr) cin>>i;
        for(auto& i: brr) cin>>i;

        long long count = 0;

        bool valid = true;
        for(long long i=0; i<n-1; i++){
            // for(long long j=i; j<n-1; j++){
            long long j= i;
                while(j<n && arr[j]>brr[i]) j++;
                if(j==n)
                {
                    i=n;
                    valid = false;
                    break;
                }
                // return;
                for(; j>i; j--){
                    auto temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    count++;
                }
            // }
        }
        // sort(arr.begin(), arr.end());
        for(long long i=0; i<n; i++){
            valid = valid && arr[i]<=brr[i];
        }
        if(valid)
        cout<<count<<endl;
        else
        cout<<-1<<endl;

    }

    return 0;
}

