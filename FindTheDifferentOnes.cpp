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
        vector<long long> a(n);        
        for(int i=0; i<n; i++)
            cin>>a[i];
        vector<int> lookup;
        for(int i=1; i<n; i++)
        {
            
            if(a[i]!=a[i-1])
            {
                lookup.push_back(i+1);
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int l, r;
            cin>>l>>r;
            int idx = upper_bound(lookup.begin(), lookup.end(), l) - lookup.begin();
            if(idx>=lookup.size())
            {
                cout<<-1<<" "<<-1<<endl;
                continue;
            }

            if(lookup[idx]<=r)
            cout<<lookup[idx]-1<<" "<<lookup[idx]<<endl;
            else
            cout<<-1<<" "<<-1<<endl;
        }
        
    }

    return 0;

}