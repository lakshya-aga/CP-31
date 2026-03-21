#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <cmath>
#include <unordered_map>
using namespace std;
int main(){
    int t;
    // cout<<"Enter"<<endl;
    cin>>t;
    while(t--){
        int n, W;
        cin>>n;
        cin>>W;
        unordered_map<int, int> arr;
        for(int i=30; i>=0; i--)
        {
            arr[1<<i] = 0;
        }
        for(int i=0; i<n; i++)
        { int temp; cin>>temp; arr[temp]++;}
        
        int curr = 0;
        int ans = 0;
        int count_n=0;
        while(count_n!=n)
        {
            ans++;
            curr=0;
            for(int i=30; i>=0; i--)
            {
            if(arr[1<<i]!=0 && (curr+(1<<i) <= W))
                {
                    curr+=1<<i;
                    arr[1<<i]--;
                    i++;
                    count_n++;
                }    
            }
        }
        cout<<ans<<endl;
    }
}