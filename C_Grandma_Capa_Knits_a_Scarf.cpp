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
    // cin>>i;
    cin>>n;
    string s;
    cin>>s;
    int ans = 1e8;
    for(auto i: "abcdefghijklmnopqrstuvwxyz")
    {
        int l = 0, r = n-1;
        int curr_ans = 0;
        while(l<=r){
            if(s[l]==s[r]){
                l++; r--;
            }
            else if(s[l]==i){
                l++;
                curr_ans++;
            }
            else if(s[r]==i){
                r--;
                curr_ans++;
            }
            else{
                curr_ans = -1;
                break;
            }
        }
        if(curr_ans==-1)
        continue;
        else
        ans = min(ans, curr_ans);
    }
    if(ans!=1e8)
    cout<<ans<<endl;
    else
    cout<<-1<<endl;


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