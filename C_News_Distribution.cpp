#include <iostream>
#include <vector>
#include <stack>
using namespace std;
template <typename T, typename T2>
void traverse(const T& adj_list, long long i, T2& visited, long long color){
    stack<long long> s;
    s.push(i);
    while(!s.empty()){
        auto curr = s.top();
        s.pop();
        if(visited[curr]!=0){
            continue;
        }
        visited[curr] = color;
        for(auto i: adj_list[curr])
        s.push(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin>>n>>m;
    vector<vector<long long>> adj_list(n+1);
    vector<long long> color(n+1, 0);
    while(m--){
        long long k;
        cin>>k;
        vector<long long> arr(k);
        for(long long i=0; i<k; i++){
            cin>>arr[i];
        }
        for(long long i=1; i<k; i++){
            adj_list[arr[0]].push_back(arr[i]);
            adj_list[arr[i]].push_back(arr[0]);
        }
        
    }
    long long idx = 0;
    // for(auto i: adj_list){
    //     cout<<idx++<<"->";
    //     for(auto j: i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    long long curr_color = 0;
    for(long long i=0; i<n; i++){
        if(color[i]==0){
            traverse(adj_list, i, color, ++curr_color);
        }
    }
    vector<long long> freq(n+1);
    for(auto c: color){
        // cout<<c<<" ";
        freq[c]++;
    }
    // cout<<endl;
    for(long long i=1; i<=n; i++){
        cout<<freq[color[i]]<<" ";;
    }
    
    cout<<endl;
}