
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
    cin>>n;
    vector<int> arr(n);
    vector<int> brr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cin>>brr[i];
    }

    // save product, index pairs, sort. then for each product find nums grater than it not equal to its index, ans+=count
    // or count all that are not equal and are not made of the same index

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // your code here
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}