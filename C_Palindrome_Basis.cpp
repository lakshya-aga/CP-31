#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

long long MOD = 1e9 + 7;
vector<long long> palindromes;
vector<long long> dp(50000, 0);
auto reverse (auto n){
    auto ans = 0;
    while(n!=0){
        ans = ans*10+n%10;
        n=n/10;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(long long i=1; i<=50000; i++){
        if(reverse(i)==i){
            palindromes.push_back(i);
        }
    }
    long long t;
    cin>>t;
    dp[0]=1;
    
    for(long long i=0; i<palindromes.size(); i++){
        for(long long j=1; j<dp.size() ; j++){
            if(j<palindromes[i]) continue;
            dp[j] = (dp[j]%MOD+dp[j-palindromes[i]%MOD])%MOD;
        }
        
        // cout<<dp[2]<<" "<<i<<endl;
    }
    while(t--){
        long long n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    // your code here
    // for(auto i: dp){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    return 0;
}