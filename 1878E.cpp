#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<long long> arr(n);
        for(int i=0; i<n; i++)
        cin>>arr[i];
        
        vector<vector<int>> count;
        
        for(int j=0; j<64; j++){
            count.push_back(vector<int>());
            count[j].push_back(0); // 0 1s before first element
            for(int i=1; i<=n; i++){
                count[j].push_back((1<<j & arr[i-1])>>j);
                // if(i!=0)
                count[j][i] = count[j][i-1]+count[j][i];
                // cout<<count[j][i]<<" ";
            }
            // cout<<endl;

        }
        
        int q;
        cin>>q;
        
        for(int i=0; i<q; i++){
            int k, l;
            cin>>l;
            cin>>k;
            
            int low = l;
            int high = n;
            if(k>arr[l-1]){
                cout<<-1<<" ";
                continue;
            }
            else{
                int ans = 0;
                while(high>=low){
                    int mid = (high+low)/2;
                    long long value=0;
                    int r=mid;
                    
                    // cout<<r<<endl;
                    for(int i=0; i<64; i++)
                    {
                        value = value + ((count[i][r] - count[i][l-1] == r-l+1 )<<i);
                        // cout<< count[i][l-1] <<" "<< count[i][r] << " "<< r-l+1 <<endl;
                    }
                    // cout<<"---------"<<endl;
                    // cout<<l<<endl;
                    // cout<<r<<endl;
                    // cout<<value<<endl;
                    // cout<<"---------"<<endl;
                    if(value>=k){
                        ans = mid;
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                cout<<ans<<" ";
            }
        }
            cout<<endl;
    }
}

