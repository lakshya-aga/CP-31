#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // std::cout<<"Hello World";
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(long long i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        long long left_idx = 0; 
        long long right_idx = n-1;
        long long combo=0;
        long long ans=0;
        while(left_idx<right_idx){
            long left = arr[left_idx];
            long right = arr[right_idx];
            if(left+combo<=right){
                combo+=left;
                ans+=left;
                arr[left_idx++] = 0;
            }
            else{
                arr[left_idx] = left - (right-combo);
                ans+=(right-combo);
                combo=right;
                arr[right_idx--]=0;
                ans++;
                combo=0;
            }
            // cout<<ans<<" "<<left_idx<<" "<<right_idx<<endl;
        }
        if(left_idx == right_idx){
            
            ans+=(arr[left_idx]+1-combo)/2;
            arr[left_idx] = arr[left_idx] - (arr[left_idx]+1-combo)/2;
            if(arr[left_idx]!=0)
            ans++;
        }
        cout<<ans<<endl;
        }
    

    return 0;
}