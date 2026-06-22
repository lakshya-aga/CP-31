#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int ans_count = 0;
int dfs(int start){
    if(visited[start])
    return 0;
    visited[start]++;
    int ans = 0;
    for(auto node: adj[start]){
        auto temp = dfs(node);
        if(temp!=0 && temp%2==0)
        ans_count++;
        ans+=temp;
    }
    
    return ans + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    adj = vector<vector<int>>(n+1);
    visited = vector<int>(n+1, 0);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(1)%2==0){
        cout<<ans_count<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    



    return 0;
}