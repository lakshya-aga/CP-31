#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long> arr(n);
        for(int i=0; i<n; i++)
        cin>>arr[i];
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        sort(arr.begin(), arr.end());
        long long ans = arr[0];
        for(int i=0; i<n-1; i++)
        ans = min(ans, arr[i+1]-arr[i]);
        if(k==1){
            cout<<ans<<endl;
            continue;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long curr = abs(arr[j] - arr[i]);
                long long left = lower_bound(arr.begin()+i, arr.begin()+j, curr) - arr.begin();
                long long right = upper_bound(arr.begin()+i, arr.begin()+j, curr) - arr.begin();

                if(right!=n)
                ans = min(ans, abs(arr[right] - curr));
                else 
                ans = min(ans, abs(arr[right-1] - curr));
                if(left!=0)
                ans = min(ans, abs(curr - arr[left-1]));
                ans = min(ans, abs(curr - arr[left]));
            }
        }
        cout<<ans<<endl;
    }
}

