#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        long long k;
        cin>>n>>k;
        vector<long long> arr(n);
        for(long long i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        unordered_map<long long, long long> freq;
        for(auto i: arr){
            freq[i]++;
        }
        long long largest = arr[0];
        long long second_largest = -1;
        bool ans = false;
        vector<long long> uniques;
        for(long long i=0; i<n; i++){
            if(i==0 || arr[i]!=arr[i-1]){
                uniques.push_back(arr[i]);
            }

        }

        for(long long i=0; i<uniques.size(); i++){
            if((i==uniques.size()-1 || uniques[i]+k < uniques[i+1]) && freq[uniques[i]]%2 == 0 ){
                ans = true;
            }
            else{
                if(i>=1 && freq[uniques[i]] % 2 != 0 && uniques[i-1]+k >= uniques[i]){
                    ans=true;
                }
            }
            if(ans) break;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    // your code here

    return 0;
}