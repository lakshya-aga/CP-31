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
        for(long long i=0; i<n; i++){
            cin>>arr[i];
        }
        long long max_a = arr[0];
        for(long long i=0; i<n; i++){
            max_a = max(arr[i], max_a);
        }
        long long min_a = arr[0];
        for(long long i=0; i<n; i++){
            min_a = min(arr[i], min_a);
        }
        cout<<max_a-min_a+1<<endl;
        
    }
    // your code here

    return 0;
}