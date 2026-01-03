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
        int n, k;
        cin>>n;
        vector<long long> a(n);        
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        long long ans = 0;
        for(int i=0; i<n; i++)
        ans = gcd(ans, a[i]);
        while(true)
        {
            ans = ans*2LL;
            int distinct = 1;
            long long prev = a[0] % ans;
            int i = 0;
            while(i<n && distinct<=1)
            {
                if(prev==a[i]%ans)
                {   
                    i++;
                    continue;
                }
                else
                {
                    distinct++;
                    prev=a[i]%ans;
                }
                i++;
                
            }
            if(distinct>1)
            break;
        }
        cout<<ans<<endl;
    }
        

    

    return 0;

}