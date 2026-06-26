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
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> cumsum(n);
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            freq[arr[i]]++;
        }

        int ans = 0;
        ans = freq[0] + min(freq[1], freq[2]) + (max(freq[1], freq[2]) - (min(freq[1], freq[2])))/3; 
        cout<<ans<<endl;

        
    }

    return 0;
}