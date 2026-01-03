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
        long long n,k;
        cin>>n;
        vector<long long> a(n);        
        for(int i=0; i<n; i++)
            cin>>a[i];
        vector<long long> prefix_sum(n);
        partial_sum(a.begin(), a.end(), prefix_sum.begin());
        long long max_diff = 0;
        for(int i=1;i<=n; i++)
        {
            if(n%i==0)
            {
                long long min_truck = prefix_sum[i-1];
                long long max_truck = prefix_sum[i-1];
                int j=i-1+i;
                while(j<n)
                {
                    min_truck = min(min_truck, prefix_sum[j] - prefix_sum[j-i]);
                    max_truck = max(max_truck, prefix_sum[j] - prefix_sum[j-i]);
                    j=j+i;
                }
                max_diff = max(max_diff, max_truck - min_truck);
            }
        }
        cout<<max_diff<<endl;   
        
    }

    return 0;

}