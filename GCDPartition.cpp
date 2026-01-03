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
        long long n;
        cin>>n;
        vector<int> a(n);        
        for(int i=0; i<n; i++)
            cin>>a[i];
        long long ans = 1; 
        long long prefix_sum = 0;
        long long total = accumulate(a.begin(), a.end(), 0LL);
        for(int i=0; i<n-1; i++)
        {
            prefix_sum+=a[i];
            total-=a[i];
            ans = max(ans, gcd(total, prefix_sum));

        }
        cout<<ans<<endl;
    }

    return 0;

}