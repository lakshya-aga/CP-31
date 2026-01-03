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
        vector<int> a(n);
        
        for(long long i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int min_a = *min_element(a.begin(), a.end());
        int ans = __INT_MAX__;
        bool flag = true;
        for(int i=0; i<n; i++)
        {
            if(a[i]==min_a)
            continue;
            flag = flag && (a[i]%(a[i]-min_a) == min_a);
            ans = min(ans, a[i] - min_a);
        }
        if(!flag)
        ans = min_a;
        cout<<ans<<endl;
        
    }

    return 0;

}