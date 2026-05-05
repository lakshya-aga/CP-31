
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

unordered_map<long long, int> dp;
int solve(int x){
    if(dp[]){

    }
}
int main()
{
   long long t;
   cin>>t;
   while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        unordered_map<long long, int> dp;
        for(long long i=0; i<n; i++)
        {
            int temp;
            cin>>temp;
            arr[i] = temp;
            dp[temp] = 1;
        }
        sort(arr.begin(), arr.end());

        for(int i=1; i<=n; i++){
            auto it = upper_bound(arr.begin(), arr.end(), i);
            dp[i] = 1<<31;
            while(it!=arr.begin()){
                if(i%*it==0 && *it!=1 && dp[i/ *it] < 1<<31)
                dp[i] = min(dp[i], dp[i/ *it]+1);
                it--;
            }
            if(dp[i]==1<<31)
            cout<<-1<<" ";
            else
            cout<<dp[i]<<" ";
        }
        cout<<endl;



   }
}