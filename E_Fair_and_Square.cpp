#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <stack>
#include <cmath>
using namespace std;


stack<long long> s;
vector<long long> sz;
vector<long long> visited;
unordered_map<long long, vector<long long>> adj;

long long dfs(long long node){
    if(visited[node])
    return 0;
    else{
        visited[node] = 1;
        for(auto i: adj[node])
        {
            sz[node] += dfs(i);
        }
        sz[node]++; //itself
        // cout<<node<<" "<<sz[node]<<endl;
        return sz[node];
    }
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> arr(n, 0);
    for(auto &i: arr) cin>>i;


    visited = vector<long long>(n+1, 0);
    sz = vector<long long>(n+1, 0);

    for(long long i=0; i<n-1; i++){
        long long u, v;
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cout<<dfs(1)<<endl; // should give n

    dfs(1);
    long long ans= 0;
    for(long long i=1; i<=n; i++){
        if(arr[i-1] == (long long)sqrt(arr[i-1])*(long long)sqrt(arr[i-1]))
        {
            // cout<<"---"<<endl;
            // cout<<arr[i-1]<<" "<<i<<endl;
            long long triples =0,  pairs = 0, total = 0;
            for(auto node: adj[i]){

                long long s = sz[node];
                if(sz[node]>sz[i]){ // parent node
                    s = n - sz[i];
                }
                // cout<<node<<":"<<s<<" ";
                triples+=pairs*s;
                pairs+=total*s;
                total+=s;
            }
            ans += triples+pairs;
            // cout<<ans<<endl;
            // cout<<endl;
        }
    }
    cout<<ans<<endl;





    adj.clear();
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