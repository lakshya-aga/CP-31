#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> a_dp(n);
    vector<long long> b_dp(n);
    for(long long i=0; i<n; i++)
    cin>>a[i];
    for(long long i=0; i<n; i++)
    cin>>b[i];
    a_dp.push_back(0);
    b_dp.push_back(0);
    a_dp[n-1]=a[n-1];
    b_dp[n-1]=b[n-1];
    for(long long i=n-2; i>=0; i--)
    {
        a_dp[i] = max(b_dp[i+1], b_dp[i+2]) + a[i];
        b_dp[i] = max(a_dp[i+1], a_dp[i+2]) + b[i];
    }
    cout<<max(a_dp[0], b_dp[0])<<endl;
}