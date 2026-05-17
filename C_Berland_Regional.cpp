#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        
        vector<long long> university(n);
        vector<long long> skill(n);
        unordered_map<long long, vector<long long>> uni_team(n);
        unordered_map<long long, vector<long long>> cumsum(n);
        
        long long initial = 0;
        for(long long i=0; i<n; i++){
            cin>>university[i];
        }
        for(long long i=0; i<n; i++){
            long long skill;
            cin>>skill;
            uni_team[university[i]].push_back(skill);
            cumsum[university[i]].push_back(skill);
        }
        // cout<<"input"<<endl;
        for(auto i: uni_team){
                // cout<<i.first<<endl;
                // cout<<i.second.size()<<endl;

                sort(i.second.begin(), i.second.end());
                reverse(i.second.begin(), i.second.end());
                partial_sum(i.second.begin(), i.second.end(), uni_team[i.first].begin());
            }

        vector<long long> ans(n, 0);
        for(auto teams: uni_team){
        for(long long i=1; i<=n; i++){
                auto temp = uni_team[teams.first].size();
                if(temp<i)
                {
                    break;
                }
                ans[i-1]+=uni_team[teams.first][temp - (temp%i) - 1];
                // cout<<ans<<","<<teams.first<<endl;
            }
        }
        for(auto i: ans){
            cout<<i<<" ";
        
        }
        cout<<endl;
    }
}