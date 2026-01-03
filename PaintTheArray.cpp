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
        // Even is divisible
        long long ans = 0;
        for(int i=0; i<n; i+=2)
        ans = gcd(ans, a[i]);
        bool flag = true;
        for(int i=1; i<n; i+=2)
        if(a[i]%ans==0)
        {
            flag = false;
            break;
        }

        if(flag)
        {
            cout<<ans<<endl;
        }
        else{
            ans = 0;
            for(int i=1; i<n; i+=2)
                ans = gcd(ans, a[i]);
            bool flag = true;
            for(int i=0; i<n; i+=2)
                if(a[i]%ans==0)
                {
                    flag = false;
                    break;
                }
            if(flag)
            cout<<ans<<endl;
            else
            cout<<0<<endl;
        

        }
        

    }

    return 0;

}