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
        long long a, b, k;
        cin>>a>>b>>k;
        
        vector<long long> boys(k);
        vector<long long> girls(k);
        vector<pair<long long, long long>> pairs(k);
        for(long long i=0; i<k; i++){
            cin>>boys[i];
        }
        for(long long i=0; i<k; i++){
            cin>>girls[i];
        }
        for(long long i=0; i<k; i++){
            pairs[i] = {boys[i], girls[i]};
        }
        sort(pairs.begin(), pairs.end());
        unordered_map<long long, long long> boys_freq;
        for(auto i: boys)
        boys_freq[i]++;

        unordered_map<long long, long long> girls_freq;
        for(auto i: girls)
        girls_freq[i]++;
        long long ans = 0;
        for(auto i: pairs){
            ans += k - boys_freq[i.first] - girls_freq[i.second]+1;
        }
        cout<<ans/2<<endl;
        

    }
}