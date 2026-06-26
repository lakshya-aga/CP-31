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

    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(auto &i: arr)
    cin>>i;

    sort(arr.begin(), arr.end());
    unordered_map<long long, long long> freq;
    for(auto i: arr) freq[i]++;

    vector<long long> unique;
    unique.reserve(n);
    for(auto i: freq){
        unique.push_back(i.first);
    }
    sort(unique.begin(), unique.end());
    swap(unique[0], unique.back());

    sort(unique.begin()+1, unique.end());

    long long curr_max = unique[0];
    long long mex = 0;
    auto ans = 0ll;
    for(long long i=0; i<unique.size(); i++){
        // cout<<unique[i]<<" ";
        if(unique[i]==mex) mex++;
        if(curr_max==mex) mex++;
        ans += (curr_max+mex);
    }
    // cout<<endl;
    ans += (n-unique.size())*(mex+curr_max);
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;
    while(t--)
    solve();

    return 0;
}

