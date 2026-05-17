#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string s;
        cin>>s;
        vector<long long> count_left(n);
        vector<long long> count_right(n);
        vector<long long> cost_left(n);
        vector<long long> cost_right(n);
        long long initial = 0;
        for(long long i=0; i<n; i++){
            if(s[i]=='*')
            count_left[i] = ++initial;
            else
            count_left[i] = initial;
        }
        initial = 0;
        for(long long i=0; i<n; i++){
            if(s[i]=='*')
            initial = initial;
            else
            initial = initial+count_left[i];
            cost_left[i] = initial;
        }
        reverse(s.begin(), s.end());

        initial = 0;
        for(long long i=0; i<n; i++){
            if(s[i]=='*')
            count_right[i] = ++initial;
            else
            count_right[i] = initial;
        }
        initial = 0;
        for(long long i=0; i<n; i++){
            if(s[i]=='*')
            initial = initial;
            else
            initial = initial+count_right[i];
            cost_right[i] = initial;
        }
        reverse(cost_right.begin(), cost_right.end());
        cost_right.push_back(0);
        long long ans=cost_right[0];
        for(long long i=0; i<n; i++){
            ans = min(ans, cost_left[i]+cost_right[i+1]);
        }
        cout<<ans<<endl;
    }
}