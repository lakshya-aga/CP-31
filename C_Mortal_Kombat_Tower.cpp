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

    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n+2, 0);
        vector<long long> me(n+2, 0);
        vector<long long> son(n+2, 0);
        for(long long i=0; i<n; i++){
            cin>>arr[i];
        }

        for(long long i=n-1; i>=0; i--){
            me[i] = min(son[i+1], son[i+2]);
            son[i] = min(me[i+1] + arr[i], me[i+2] + arr[i] + arr[i+1]);

        }
        cout<<son[0]<<endl;

    }

    return 0;
}