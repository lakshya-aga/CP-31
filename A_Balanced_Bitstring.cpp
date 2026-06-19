#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;


void solve(){
    int n; int k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<char> track(k, '?');
    for(int i=0; i<n; i++){
        if(track[i%k]=='?'){
            track[i%k] = s[i];
        }
        if(s[i]!=track[i%k] && s[i]!='?'){
            cout<<"NO\n";
            return;
        }
    }
    vector<char> new_s(n);
    for(int i=0; i<n; i++){
        new_s[i]=track[i%k];
    }
    unordered_map<char, int> freq;
    for(int i=0; i<k; i++){
        freq[new_s[i]]++;
    }
    if(freq['0']<=k/2 && freq['1']<=k/2)
    cout<<"YES\n";
    else
    cout<<"NO\n";
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