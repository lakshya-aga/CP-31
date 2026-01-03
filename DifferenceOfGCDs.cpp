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
        long long n,l,r;
        cin>>n>>l>>r;
        
        
        vector<int> ans(n);
        int i = n;
        for(; i>=1; i--)
        {
            ans[i-1] = (r/i)*i >= l ? (r/i*i): -1;
            if(ans[i-1]==-1)
            {
                cout<<"NO"<<endl;
                break;
            }
        }
        if(i==0)
        {
            cout<<"YES"<<endl;
            for(auto i: ans)
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;

}