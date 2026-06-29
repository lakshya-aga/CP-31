#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> divisors;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0)
        {
            divisors.push_back(i);
            if(i!=n/i) 
            divisors.push_back(n/i);
        }
    }
    divisors.push_back(n);
    sort(divisors.rbegin(), divisors.rend());

    vector<vector<int>> layers;
    for(auto i: divisors){
        // cout<<i<<endl;
        // if(layers.size()==0){
        //     layers.push_back({i});
        // }
        // else{
        bool existing = false;
        for(auto &l: layers){
            // cout<<"layer";
            auto flag1 = true;
            auto flag2 = false;
            for(auto num: l){
                if(num%i == 0){
                    flag1 = false;
                }
                if(gcd(num, i) != 1){// also check the next numbers it displces
                    flag2=true;
                }
            }
            if(flag1 && flag2)
            {
                l.push_back(i);
                existing = true;
                break;
            }
            
        }
        if(!existing)
        layers.push_back({i});
    }
    cout<<layers.size()<<endl;
    // cout<<endl;
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