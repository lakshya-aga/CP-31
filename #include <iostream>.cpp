#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

void solve(){
    long long n, k;
    cin>>n>>k;
    vector<long long> arr(n);
    unordered_map<long long, long long> freq(n+1);
    unordered_map<long long, long long> fof(n+1);
    long long d = 0;
    for(long long i=0; i<n; i++){
        cin>>arr[i];
        freq[arr[i]]++;
        if(freq[arr[i]]==1)
        d++;
    }
    for(auto i: freq) fof[i.second]++;
    vector<pair<long long, int>> fof_elems;
    for(auto i: fof){
        fof_elems.push_back({i.second, i.first});
    }
    long long b = 0;
    auto curr_n = n;
    curr_n = curr_n - 0;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}