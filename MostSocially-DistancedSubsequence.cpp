#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(i==0){
                ans.push_back(arr[0]);
                continue;
            }
            if(i==n-1){
                ans.push_back(arr[i]);
                continue;
            }
            if((arr[i]<arr[i-1] && arr[i]<arr[i+1]) || (arr[i]>arr[i-1] && arr[i]>arr[i+1]))
                ans.push_back(arr[i]);
        }
        cout<<ans.size()<<endl;
        for(auto i: ans) cout<<i<<" ";
        cout<<"\n";
    }
}