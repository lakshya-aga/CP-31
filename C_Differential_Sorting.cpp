#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    // vector<int> suff_max(n);
    // inclusive_scan(arr.rbegin(), arr.rend(), suff_max.rbegin(),
    // [](int x, int y){return max(x,y);});
    // vector<int> curr_min(n);
    // for(int i=n-2; i>=0; i--){
    //     curr_min[i] = arr[i] - suff_max[i+1];
    // }
    // inclusive_scan(curr_min.rbegin()+1, curr_min.rend(), curr_min.rbegin()-1, 
    // [](int x, int y){return min(x,y);});

    if(n>=3){
        arr[n-3] = arr[n-2]-arr[n-1];
        if(arr[n-3]>arr[n-2] || arr[n-2]>arr[n-1])
        cout<<-1<<endl;
        else{
            cout<<n-2<<endl;
            for(int i=0; i<n-2; i++){
                cout<<i+1<<" "<<n-2<<" "<<n-1<<endl;
            }
        }
    }



}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}