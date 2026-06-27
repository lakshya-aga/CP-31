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
    string s;
    cin>>s;
    vector<long long> pref(n);
    pref[0] = ((s[0]=='1'?1:-1)+3)%3;
    for(long long i=1; i<n; i++){
        pref[i] = (((pref[i-1]+(s[i]=='1'?1:-1)))%3+3)%3;
    }
    // for(auto i: pref) cout<<i<<" ";
    // cout<<"\n";
    vector freq = {1,0,0};
    long long y = 1;
    long long ans = 0;
    for(long long i=0; i<n; i++){
        ans= ans + i - freq[pref[i]%3] + 1;
        if(i!=0 && s[i]!=s[i-1]) y++;
        else y=1;
        ans = ans - (y-1)/2;

        // cout<<i+1<<"-"<<freq[pref[i]%3]<<"-("<<y<<"-1)/2 ";
        freq[pref[i]%3]++;

    }
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