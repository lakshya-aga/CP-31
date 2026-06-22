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
    long long n, x, y, z;
    cin>>n>>x>>y>>z;

    //case no ai
    auto ans1 = (n)/(x+y);
    if(n%(x+y)!=0)
    ans1++;
    auto ans2 = (n - z*x)/(10*y+x) + z;
    if ((n - z*x)%(10*y+x)!=0)
    ans2++;

    cout<<min(ans1, ans2)<<endl;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}