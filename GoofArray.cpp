#include <iostream>

#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long> arr(n);
    unordered_map<long long, long long> freq;
    for(long long i=0; i<n; i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }

    long long total = 0;
    // for(auto i: present)
    // {cout<<i.first<<":";
    // for(auto j: i.second)
    // {cout<<j<<",";} cout<<endl;}
    

    for(auto i: arr)
    total+=i;
    // cout<<"Total:"<<total<<endl;
    long long ans = 0;
    
    vector<long long> nice_idx;
    for(long long i=0; i<n; i++)
    {
        // cout<<"total-i"<<total-i<<endl;
        
        if((total-arr[i])%2 == 0 
        && freq.find((total-arr[i])/2)!=freq.end() 
        && !(arr[i]==(total-arr[i])/2 && freq[arr[i]]<2))
        {
            // cout<<i<<endl;
            ans++;
            nice_idx.push_back(i+1);

        }
        
    }
    cout<<ans<<endl;
    for(auto i: nice_idx)
    cout<<i<<" ";
    cout<<"\n";

}