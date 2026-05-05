#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

#include <iomanip>

int main(){

    int t;
    cin>>t;
    while(t--){
        
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<int> brr(k);
    for(int i=0; i<k; i++){
        cin>>brr[i];
    }
    
    vector<int> complement_count(n);
    int complement = 0;
    if(arr[brr[0]-1] == 1){
        complement = 0;
    }
    else{
        complement = 1;
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==complement){
            count++;
        }
        complement_count[i] = count;
    }
    // for(auto i: arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    
    // for(auto i: complement_count){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    
    int ans = 0;
    for(int i=0; i<n; i++){
        int l = lower_bound(brr.begin(), brr.end(), i+1) - brr.begin();
        int r = l+1;
        if(brr[l]-1>i){
            l=0;
        }
        r = min(k-1, r);
        if(brr[r]-1<=i){
            l = r;
        }
        cout<<l<<","<<r<<endl;
        if(arr[i]==complement)
        {
            ans = max(min(abs(complement_count[brr[l]] - complement_count[i])*2,
                          abs(complement_count[brr[r]] - complement_count[i])*2)
            , ans);
        }
    }
    cout<<ans<<endl;
    }
}