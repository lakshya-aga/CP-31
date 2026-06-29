#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

vector<int> parent;
vector<int> distance_to_root;

int dfs(int node){
    if(node==1)
    return 0;
    else
    if(distance_to_root[node]==-1)
    distance_to_root[node] = dfs(parent[node])+1;
    return distance_to_root[node];

}
void solve(){
    int n; cin>>n;
    parent = vector(n+1, 0);
    distance_to_root = vector(n+1, -1);
    for(int i=2; i<=n; i++) cin>>parent[i];
    distance_to_root[1] = 0;
    for(int i=1; i<=n; i++){
        distance_to_root[i] = dfs(i);
        // cout<<distance_to_root[i]<<" "<<i<<endl;
    }
    auto ans = max_element(distance_to_root.begin(), distance_to_root.end());
    cout<<(*ans+1)<<endl;

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