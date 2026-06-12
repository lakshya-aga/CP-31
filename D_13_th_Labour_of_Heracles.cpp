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
    vector<int> weights(n);
    for(int i=0; i<n; i++)
    cin>>weights[i];
    unordered_map<int, int> degree;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u;
        cin>>v;
        degree[u]++;
        degree[v]++;
    }
    for(auto i: degree){
        i.first;
        i.second;

    }
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