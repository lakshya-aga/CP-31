#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;
int main(){
    long num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<pair<ll,ll>> arr(n);
        
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].first;
            cin>>arr[i].second;
        }
        ll min_src = 4LL*1000000000LL;
        ll min_dest = 4000000000LL;
        for(int i=0; i<k; i++)
        {
            min_src = min(min_src, abs(arr[a-1].first - arr[i].first) + abs(arr[a-1].second - arr[i].second));
            min_dest = min(min_dest, abs(arr[b-1].first - arr[i].first) + abs(arr[b-1].second - arr[i].second));
        }
        ll ans = min(min_src+min_dest, abs(arr[a-1].first - arr[b-1].first) + abs(arr[a-1].second - arr[b-1].second));
        cout<<ans<<endl;
    }

    return 0;

}