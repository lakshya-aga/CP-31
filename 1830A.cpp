#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> dp;
        vector<int> pos;
        vector<int> visited;
        vector<vector<int>> neighbours(n+1);
        vector<vector<int>> edge_position(n+1);
        dp = vector<int>(n+1);
        pos = vector<int>(n+1);
        visited = vector<int>(n+1);
        dp[1]=1;
        pos[1] = 0;
        for(int i=1; i<n; i++){
            int u, v;
            cin>>v;
            cin>>u;
            neighbours[u].push_back(v);
            neighbours[v].push_back(u);
            edge_position[u].push_back(i);
            edge_position[v].push_back(i);

        }

        queue<int> q;
        q.push(1);
        dp[1] = 1;
        pos[1] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited[curr]==1)
            continue;
            visited[curr] = 1;
            auto neighbor = neighbours[curr];
            for(int i=0; i<neighbours[curr].size(); i++){
                if(edge_position[curr][i] < pos[curr]){
                    dp[neighbours[curr][i]] = dp[curr] + 1;
                }
                else{
                    dp[neighbours[curr][i]]=dp[curr];

                }
                pos[neighbours[curr][i]] = edge_position[curr][i];
                q.push(neighbor[i]);
            }

        }
        int ans = 1;
        for(int i=1; i<=n; i++)
        {
        ans = max(ans, dp[i]);}
        cout<<ans<<endl;
    }
}

