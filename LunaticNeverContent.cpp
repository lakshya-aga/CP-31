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
        
        int ans = 0;

        for(int i=0; i<(n+1)/2; i++)
        {
            ans = gcd(ans, a[i] - a[n-i-1]);
        }
        cout<<ans<<endl;
    }

    return 0;

}