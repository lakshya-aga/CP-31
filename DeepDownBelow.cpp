#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        vector<pair<int, int>> req_gain;
        
        while(num--)
        {
            int k;
            cin>>k;
            vector<int> temp(k);
            
            for(int i=0; i<k; i++)
            cin>>temp[i];

            int curr_req_max = temp[0]+1;
            for(int i=0; i<k; i++)
            curr_req_max = max(temp[i]-i+1, curr_req_max);

            req_gain.push_back(pair<int, int>(curr_req_max, k));

            
        }
        sort(req_gain.begin(), req_gain.end());
        int curr_power = 0;
        int ans = req_gain[0].first;
        for(auto i: req_gain)
        {
            ans = max(ans, i.first - curr_power);
            curr_power += i.second;
        }
        cout<<ans<<endl;
    }
}