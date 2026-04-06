/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    int n;
    int k;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans = 0;
        int curr = 1;
        for(int i=1; i<n; i++){
            if(arr[i-1]<arr[i]*2){
                curr++;
            }
            else{
                ans+=max(0, curr-k);
                curr=1;
            }
        }
        ans+=max(0, curr-k);
        cout<<ans<<endl;
    }

    return 0;
}