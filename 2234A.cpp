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
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        int curr_mod = arr[0]%arr[1];
        bool ans(true);
        for(int i=2; i<n; i++){
            if(arr[i]!=curr_mod)
            {
                ans = false;
                break;
            }
            curr_mod = arr[i-1]%arr[i];
        }
        if(ans){
            cout<<arr[0]<<" "<<arr[1]<<endl;
        }
        else
        cout<<-1<<endl;
    }

    return 0;
}