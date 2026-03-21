#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
int main()
{
    int t;
    // cout<<"ENter"<<endl;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> count(31);
        vector<int> arr(n);

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            for(int j=0; j<31; j++)
            if(arr[i] & 1<<j)
            count[j]++;
        }
        int curr_gcd = count[0];
        for(auto c: count)
        {
            curr_gcd = __gcd(c, curr_gcd);
        }
        // cout<<"GCD "<<curr_gcd<<endl;
        for(int i=1; i<=n; i++)
        if(curr_gcd%i==0)
        cout<<i<<" ";
        
        cout<<endl;


    }
}