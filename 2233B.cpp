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
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> deleted(n, 0);
        auto ans = deleted;
        auto least_penalty = 1e9;
        // cout<<"k:"<<k<<endl;
        for(int i=0; i<=k; i++){
            auto removed = 0;
            deleted = vector<int>(n, 0);
            // cout<<"i:"<<i<<endl;
            // for(auto i: deleted){
            // cout<<i;
            // }
            // cout<<endl;
            for(int l=0; l<n && removed<i; l++){
                if(s[l]=='(')
                {
                    deleted[l]=1;
                    removed++;
                }
            }
            // for(auto i: deleted){
            // cout<<i;
            // }
            // cout<<endl;
            removed = 0;
            for(int r=n-1; r>=0 && removed<k-i; r--){
                if(s[r]==')')
                {
                    deleted[r]=1;
                    removed++;
                }
            }
            // for(auto i: deleted){
            // cout<<i;
            // }
            // cout<<endl;
            auto curr_count = 0;
            auto penalty = 0;
            for(int i=0; i<n; i++){
                if(deleted[i])
                continue;
                if(s[i]=='('){
                    curr_count++;
                }
                if(s[i]==')' && curr_count>0)
                {
                    curr_count--;
                    penalty++;
                }
            }
            if(penalty<least_penalty){
                ans = deleted;
                least_penalty = penalty;
            }
        }
        for(auto i: ans){
            cout<<i;
        }
        cout<<endl;

    }

    return 0;
}