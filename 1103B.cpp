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
        string s;
        cin>>s;
        long long count = 0;
        vector<int> parity(k, 0);
        for(int j=0; j<k; j++){
            int i=j;
              while(i<n){
                if(s[i]=='1')
                parity[j]++;
                i+=k;
              }
        }
        bool ans = true;
        for(int i=0; i<k; i++){
            ans = ans && (parity[i]%2==0);
        }
        if(ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    // your code here

    return 0;
}