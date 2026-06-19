#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n, 0);
        vector<vector<int>> pos(n+1);

        // for(auto &i: pos){
        //     i.push_back(-1);
        // }
        // return 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            pos[arr[i]].push_back(i);
        }

        // for(auto &i: pos){
        //     i.push_back(n);
        // }

        vector<int> ans(n+1, -1);
        for(int i=1; i<=n; i++){
            if(pos[i].size() == 0) continue;
            pos[i].push_back(n);
            int min_k = pos[i][0]+1;
            for(int j=1; j<pos[i].size(); j++){
                min_k = max(min_k, pos[i][j] - pos[i][j-1]);
            }
            
            int j=min_k;
            while(j<=n && ans[j]==-1){
                ans[j++] = i;
            }
        }

        for(int i=1; i<=n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";

        
    }

    return 0;
}