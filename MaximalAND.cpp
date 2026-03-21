#include <iostream>

#include <vector>
using namespace std;
int main()
{
    int t;
    int k;
    int num;
    // cout<<"enter"<<endl;
    cin>>t;
    while(t--)
    {
        cin>>num;
        cin>>k;
        vector<int> arr(num);
        for(int i=0; i<num; i++)
        cin>>arr[i];

        int ans = 0;

        vector<int> count(31);

        for(int i=30; i>=0; i--)
        for(auto curr: arr)
        {
            if((curr & 1<<i) == 1<<i)
            count[i]++;
        }
        
        for(int i=30; i>=0; i--)
        {
            // cout<<i<<","<<count[i]<<","<<k<<endl;
            if(k>=num - count[i])
            {
                ans+=1<<i;
                k-=num - count[i];
            }
        
        }
        cout<<ans<<endl;
    }
}