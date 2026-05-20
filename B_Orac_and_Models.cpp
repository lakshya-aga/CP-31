#include <iostream>
#include <vector>
using namespace std;
vector<long long> dp;
long long solve(long long i, const vector<long long>& arr, long long n){
    // cout<<i<<endl;
    if(i>n)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    long long ans = 1;
    
    for(long long start=i*2; start<=n; start+=i){
        if(arr[start]>arr[i])
        ans = max(solve(start, arr, n) + 1, ans);
    }
    dp[i] = ans;
    return ans;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n+1);
        dp = vector<long long>(n+1, -1);
        for(long long i=1; i<=n; i++){
            cin>>arr[i];
        }
        
        long long ans = solve(1, arr, n);
        for(int i=2; i<=n; i++){
            ans = max(ans, solve(i, arr, n));
        }
        // for(auto i: dp){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        cout<<ans<<endl;
        
    }
}