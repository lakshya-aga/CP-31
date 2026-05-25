#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n+2);
        vector<int> dp(n+2);
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        dp[n+1]=0;
        for(int i=n; i>0; i--){
            if(i+arr[i]+1 <= n+1)
            dp[i] = min(1+dp[i+1], dp[i+arr[i]+1]);
            else 
            dp[i] = 1 + dp[i+1];

        }
        cout<<dp[1]<<endl;
    }
}
