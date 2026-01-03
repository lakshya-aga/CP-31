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

        vector<int> b(n);
        
        for(long long i=0; i<n; i++)
        {
            cin>>b[i];
        }

        int l_ans = 0;
        int r_ans = 0;
        int longest = 1;
        int curr = 0;
        bool finalised = false;
        for(int l=0, r=0; l<n && r<n; )
        {
            while(r<=l)
            {
                r++;
            }
            while(r<n && b[r]>=b[r-1])
            {
                curr++;
                r++;
            }
            for(int i=l; i<r; i++)
                finalised = finalised || a[i]!=b[i];
            if(finalised)
            {
                l_ans = l;
                r_ans = r;
                longest = curr;
                break;
            }
            if(longest<curr)
            {
                l_ans = l;
                r_ans = r;
                longest = curr;
            }
            l=r;
            curr=0;
        }
        cout<<l_ans+1<<" "<<r_ans<<endl;
        
    }

    return 0;

}