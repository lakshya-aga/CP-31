#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        cin>>k;
        vector<long long> arr(n);
        for(long long i=0; i<n; i++)
        cin>>arr[i];

        vector<long long> brr(k);
        for(long long i=0; i<k; i++)
        cin>>brr[i];

        sort(arr.begin(), arr.end());

        long long ans = 0;
        for (long long i=n-1; i>=0; i--){
        ans += min((n-i-1<k ? brr[n-i-1] : brr[arr[i]-1]), arr[i]-1>=0 ? brr[arr[i]-1]:brr[n-i-1]);
        // cout<<ans<<","<<(n-i-1<k ? brr[n-i-1] : brr[arr[i]-1]) <<","<<(arr[i]-1>=0 ? brr[arr[i]-1]:brr[n-i-1])<<","<<endl;
        }

        cout<<ans<<endl;
    }
}