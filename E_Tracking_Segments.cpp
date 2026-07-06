#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <unordered_map>
using namespace std;

void solve(){
    long long n, m;
    cin>>n>>m;
    vector curr_state(n+1, 0);
    vector segments(m, vector<long long>(2, 0));
    for(long long i=0; i<m; i++){
        cin>>segments[i][0];
        cin>>segments[i][1];
    }
    long long q = 1;
    cin>>q;
    long long high = q-1;
    long long low = 0;
    vector queries(q, -1);
    for(auto &i: queries)
    cin>>i;
    vector<long long> pref(n+1);
    long long ans = 1e7;
    while(low<=high){
        long long mid = (high+low)/2;
        // cout<<mid+1<<endl;

        for(long long i=0; i<=mid; i++)
        curr_state[queries[i]]=1;
        for(long long i=mid+1; i<=q-1; i++)
        curr_state[queries[i]]=0;

        inclusive_scan(curr_state.begin(), curr_state.end(), pref.begin());
    
        bool found = false;
        for(auto &segment: segments){
            // cout<<segment[0]<<" "<<segment[1]<<endl;
            if(pref[segment[1]] - pref[segment[0]-1] > (segment[1]-segment[0]+1)/2)
            {
                ans = min(ans, mid+1);
                high = mid-1;
                found = true;
                break;
            }
        }
        if(!found)
        low=mid+1;
        
    }
    if(ans==1e7)
    cout<<-1<<endl;
    else
    cout<<ans<<endl;


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