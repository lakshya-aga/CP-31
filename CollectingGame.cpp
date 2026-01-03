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
        vector<pair<long long, long long>> a(n);
        vector<long long> out(n);
        
        for(long long i=0; i<n; i++)
        {
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a.begin(), a.end());
        vector<long long> a_sum(n);
        long long curr =0;
        for(long long i=0; i<n; i++)
        {
            curr+=a[i].first;
            a_sum[i]=curr;
        }
        out[n-1]=n-1;
        for(long long i=n-2; i>-1; i--)
        {
            auto idx = upper_bound(a.begin(), a.end(), pair<long long,long long>{a_sum[i], n});
            out[i] = min(n-1, max(out[idx-a.begin()-1],i));
        }
        vector<int> final_out(n);
        for(int i=0; i<n; i++)
        {
            final_out[a[i].second] = out[i];
        }
        for(long long i=0; i<n; i++)
        cout<<final_out[i]<<" ";

        cout<<endl;
    }

    return 0;

}