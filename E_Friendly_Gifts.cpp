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
    long long n;
    cin>>n;
    vector<long long> arr(n);
    vector<long long> temp(n+1);
    vector<vector<long long>> subsegments(n+1, vector<long long>(n+1, 0));
    for(auto &i: arr) cin>>i;
    for(long long l=0; l<n; l++){
        long long curr_min = arr[l];
        long long curr_max = arr[l];

        for(long long r = l; r<n; r++){
            curr_max = max(curr_max, arr[r]);
            curr_min = min(curr_min, arr[r]);
            if(temp[arr[r]]==0 && r-l==curr_max-curr_min)
            subsegments[curr_max][curr_min] = 1;
            if (temp[arr[r]]==1) break;
            temp[arr[r]]=1;
        }
        temp = vector<long long>(n+1, 0);
    }

    // for(auto &i: subsegments){
    //     for(auto j: i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    for(long long i=n/2; i>=0; i--){
        for(long long j=i+1; j+i<=n; j++){
            // cout<<j<<" "<<j+i<<endl;
            if(subsegments[j+i][j]==1 && subsegments[j-1][j-i-1] == 1)
            {
                // cout<<j<<endl;
                cout<<(i+1)<<endl;
                return;
            }
        }
    }
    cout<<0<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}