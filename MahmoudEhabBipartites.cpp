#include <iostream>

#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> bucket1;
    set<int> bucket2;
    vector<vector<int>> adj_list(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u;
        cin>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // for(int i=1; i<n+1; i++){
    //     cout<<i<<":";
    //     for(auto j: adj_list[i]){
    //         cout<<j<<",";
    //     }
    //     cout<<"\n";
    // }
    int count_node = 0;
    stack<int> s;
    s.push(1);
    bucket1.insert(1);
    while(bucket1.size()+bucket2.size()!=n){
        auto curr = s.top();
        s.pop();
        // cout<<curr<<endl;
        auto curr_list = adj_list[curr];
        if(bucket1.find(curr) != bucket1.end()){
            // count_node++;
            bucket1.insert(curr);
            for(auto neighbour : curr_list)
            {
                if (bucket2.find(neighbour)==bucket2.end())
                {
                    s.push(neighbour);
                    bucket2.insert(neighbour);
                }
            }
        }
        else if(bucket2.find(curr) != bucket2.end()){
            // count_node++;
            bucket2.insert(curr);
            for(auto neighbour : curr_list)
            {
                if (bucket1.find(neighbour) == bucket1.end())
                {
                    s.push(neighbour);
                    bucket1.insert(neighbour);
                }
            }
        }
    }
    // for(auto j: bucket1){
    //         cout<<j<<",";
    //     }
    //     cout<<"\n";
    // for(auto j: bucket2){
    //         cout<<j<<",";
    //     }
        // cout<<"\n";
    cout<<bucket1.size()*bucket2.size()-n+1<<endl;
}