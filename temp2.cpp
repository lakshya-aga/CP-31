#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long long n, x1, x2, k;

        cin>>n>>x1>>x2>>k;

        if(n<=3)
        {
            cout<<1<<endl;
            continue;
        }

        long long res1 = abs(max(x1, x2) -min(x1, x2))+k;
        long long res2 = abs((min(x1,x2) + n) - max(x1, x2))+k;
        // if(res1==res2)
        // res1--;

        long long ans = min(res1, res2);
        cout<<ans<<endl;

        
    }

    return 0;
}