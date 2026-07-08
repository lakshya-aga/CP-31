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
    int k;
    cin>>k;
    vector arr(k, 0);

    for(auto &i: arr) cin>>i;

    int freq1 = 0;
    int freq2 = 0;
    for(auto i: arr){
        if(i>=3){
            cout<<"YES"<<endl;
            return ;
        }
        if(i==2){
            freq2++;
            if(freq2==2){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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