#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;
int main(){
    long long num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        int n;
        cin>>n;
        vector<int> a(n);        
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        vector<int> prefix_sum(n);
        partial_sum(a.begin(), a.end(), prefix_sum.begin());
        long long suffix = 0;
        int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            suffix+=a[i];
            int idx = lower_bound(prefix_sum.begin(), prefix_sum.end(), suffix) - prefix_sum.begin();
            if(prefix_sum[idx] == suffix && i>idx)
            {
                ans = max(ans, n-i+idx+1);
            }
        }
        cout<<ans<<endl;

    }

    return 0;

}