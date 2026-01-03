#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;
int main(){
    long num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        long n,x;
        cin>>n>>x;
        vector<int> a(n);
        
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        // sort(a.begin(), a.end());
        long long low = 0;
        long long high = 2000000000;
        long long h = (high+low)/2;
        while(high>=low)
        {
            int ans = 0;
            for(int i=0; i<n; i++)
            {
                ans=ans+max(h-a[i], 0LL);
                if(ans>x)
                {
                    high = h-1;
                    h = (high+low)/2;
                    break;
                }
            }
            if(ans<=x)
            low=h+1, h=(high+low)/2;
        }
        cout<<high<<endl;
    }

    return 0;

}