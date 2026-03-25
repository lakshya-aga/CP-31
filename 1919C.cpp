#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
        cin>>arr[i];
        
        int ans = 0;
        int x = 1000000;
        int y = 1000000;

        for(auto i: arr){
            if(x < y){
                swap(x, y);
            }
            // cout<<"x:"<<x<<endl;
            // cout<<"y:"<<y<<endl;
            // cout<<"i:"<<i<<endl;
            if(i>x && i>y){
                y = i;
                ans++;
                continue;
            }
            else if(i<=x && i>=y){
                x = i;
                continue;
            }
            else if(i<=x && i<=y){
                y = i;
            }
            
            
        }
        cout<<ans<<endl;
    }
}
// -----------y---------x------------
// https://codeforces.com/problemset/problem/1919/C
