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
    int n;
    char c;
    string original;
    cin>>n;
    cin>>c;
    cin>>original;
    auto all_same = true;
    for(int i=0; i<n; i++){
        all_same = all_same && (original[i]==c);
    }
    if(all_same){
        cout<<0<<"\n";
        return;
    }
    for(int i=(n)/2; i<n; i++){
        if(original[i]==c){
            cout<<1<<"\n";
            cout<<i+1<<"\n";
            return;
        }
    }
    cout<<2<<"\n";
    cout<<n<<" "<<n-1<<"\n";

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