#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<unordered_map<char, int>> freq((k+1)/2);
    vector<int> max_freq((k+1)/2, 0);
    for(int i=0; i<n; i++){
        int correct_idx = 0;
        if(i%k < (k+1)/2){
            correct_idx = (i%k);
        }
        else
        correct_idx = k-(i%k)-1;

        // cout<<i<<" "<<correct_idx<<"\n";
        freq[correct_idx][s[i]]++;
        max_freq[correct_idx] = max(max_freq[correct_idx],freq[correct_idx][s[i]]);
    }
    int ans = 0;
    for(int i=0; i<(k+1)/2; i++){
        ans+= (2*(n/k) - max_freq[i]);
    }
    if(k%2==1)
    ans-=(n/k);

    int x = 0;

    // for(auto i: freq){
    //     cout<<x++<<endl;
    //     for(auto j: i){
    //         cout<<j.first<<" "<<j.second<<endl;
    //     }
    //     cout<<endl;
    // }


    cout<<ans<<endl;

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