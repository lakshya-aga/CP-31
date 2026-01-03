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
        long long n, x, y;
        cin>>n>>x>>y;
        vector<long long> a(n);        
        for(int i=0; i<n; i++)
            cin>>a[i];
        map<pair<long long, long long>, long long> lookup;
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            long long xx = (x-a[i]%x)%x;
            long long yy = a[i]%y;
            ans += lookup[pair<long long, long long>{xx, yy}];
            lookup[pair<long long, long long>{a[i]%x, a[i]%y}]++;
        }
        cout<<ans<<endl;
    }

    return 0;

}