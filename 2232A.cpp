#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
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
        for(int i=0; i<n; i++)
        cin>>arr[i];

        set<int> present;
        int count = 0;
        sort(arr.begin(), arr.end());
        int mid = arr[n/2];
        // cout<<mid<<endl;
        int left = 0;
        for(int i=0; i<n/2; i++){
            if(arr[i]!=mid)
            left++; 
        }

        int right = 0;
        for(int i=n/2+1; i<n; i++){
            if(arr[i]!=mid)
            right++; 
        }

        int left2 = 0;
        int right2 = 0;
        if(n%2==0){
            int mid2 = arr[n/2-1];
            // cout<<mid<<endl;
            for(int i=0; i<n/2-1; i++){
                if(arr[i]!=mid2)
                left2++; 
            }

            for(int i=n/2; i<n; i++){
                if(arr[i]!=mid2)
                right2++; 
            }
            // cout<<max(left2, right2)<<endl;
            cout<<min(max(left2, right2), (max(left, right)))<<endl;
            continue;

        }


        cout<<(max(left, right))<<endl;
    }

    return 0;
}