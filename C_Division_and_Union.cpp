#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> segments(n);
        for(int i=0; i<n; i++){
            int l, r;
            cin>>l>>r;
            segments[i] = {l,r,i};
        }
        sort(segments.begin(), segments.end());
        vector<int> ans(n, 2);
        auto right_max = segments[0][1];
        ans[segments[0][2]] = 1;
        for(int i=1; i<n; i++){
            if(segments[i][0]>right_max)
            break;
            ans[segments[i][2]]=1;
            right_max = max(right_max, segments[i][1]);
        }
        if(accumulate(ans.begin(), ans.end(), 0)==n)
        cout<<-1;
        else
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int n;


    return 0;
}