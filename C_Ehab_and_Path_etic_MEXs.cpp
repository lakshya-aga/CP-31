#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> ans(n);
    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<pair<int, int>> input_order;
    int curr = 0;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        input_order.push_back({u,v});
        
    }
    for(int i = curr, j=0; j<n-1; j++, i++){
        if(ans[j]==-1)
        ans[j]=curr++;
        cout<<ans[j]<<endl;
    }

    

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}