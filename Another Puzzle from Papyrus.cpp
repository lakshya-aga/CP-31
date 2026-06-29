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
    int n, c;
    cin>>n>>c;
    vector arr(n, n);
    vector brr(n, n);
    // cout<<n<<c<<endl;
    for(auto &i: arr) cin>>i;
    for(auto &i: brr) cin>>i;

    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i]>=brr[i]){
            ans+=(arr[i]-brr[i]);
        }
        else{
            ans = -1;
            break;
        }
    }
    // cout<<"alternate "<<ans<<endl;
    if(ans==-1){
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        ans = c;
        for(int i=0; i<n; i++){
            if(arr[i]>=brr[i]){
                continue;
            }
            else{
                ans = -1;
                break;
            }
        }
        if(ans!=-1){
            ans += accumulate(arr.begin(), arr.end(), 0);
            ans -= accumulate(brr.begin(), brr.end(), 0);
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return;
    }
    // if(ans!=-1){
    // }
    // else{
        cout<<ans<<endl;
    // }

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