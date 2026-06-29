

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
using namespace std;
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector arr(n+1, 0ll);
    vector<set<int>> adj(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        adj[i].insert(arr[i]);
        adj[arr[i]].insert(i);
    }
    vector<int> visited(n+1, 0);
    int group = 1;

    // for(auto i: adj){
    //     for(auto node: i){
    //         cout<<node<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    vector<int> stack;
    for(int i=1; i<=n; i++){
        stack.push_back(i);
        while(!stack.empty()){
            auto curr = stack.back();
            stack.pop_back();
            if(visited[curr]!=0)
            continue;
            visited[curr] = i;
            for(auto node: adj[curr]){
                stack.push_back(node);
            }
        }
    }
    int count_unique = 0;
    unordered_map<int, int> present;
    for(int i=1; i<=n; i++) 
        {
            if(present[visited[i]]==0)
            count_unique++;
            present[visited[i]]++;
        }

    vector open_count(n+1, 0);
    for(int i=1; i<=n; i++){
        // cout<<visited[i]<<" ";
        if(adj[i].size()!=2){
            open_count[visited[i]]=1;
        }
    }
    // cout<<"\n";
    auto diff = accumulate(open_count.begin(), open_count.end(), 0);
    if(diff>0) diff = diff-1;
    cout<<count_unique-diff<<" "<<count_unique<<endl;

    // count number of diconnected sections. if got 2 openings, it can be connected to any others. so min = number of disconnected with 2 openings -> 1 + closed off
    // and max is number of disconnected as they can just have their loops closed to form a dance
        
    
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