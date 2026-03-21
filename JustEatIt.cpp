#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long net_total = 0;
        vector<long long> arr(n);
        for(long long i=0; i<n; i++){
            cin>>arr[i];
            net_total += arr[i];
        }

        long long curr_min = 0;
        long long ans = arr[0];
        long long curr = 0;
        // excpet last one
        for(long long i=0; i<n-1; i++){
            curr = curr + arr[i];
            curr_min = min(curr, curr_min);
            ans = max(ans, curr - curr_min);
        }

        curr_min = 0;
        // long long ans = arr[0];
        curr = 0;
        // excpet first one
        for(long long i=1; i<n; i++){
            curr = curr + arr[i];
            curr_min = min(curr, curr_min);
            ans = max(ans, curr - curr_min);
        }

        

        if(ans < net_total)
            cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }

    }
}