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

    // your code here
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        
        for(long long i=0; i<n; i++)
        cin>>a[i];
        
        for(long long i=0; i<n; i++)
        cin>>b[i];

        // cout<<"prefix"<<endl;
        vector<long long> pref(n+1, 0);
        partial_sum(b.begin(), b.end(), pref.begin()+1);

        vector<long long> freq(n+1, 0);
        vector<long long> partial(n+1, 0);
        for(int i=0; i<n; i++){
            auto search_term = a[i]+pref[i];
            auto idx = upper_bound(pref.begin()+1, pref.end(), search_term)-pref.begin();
            freq[idx-1]--;
            freq[i]++;
            partial[idx-1]+=search_term - pref[idx-1];
        }

        partial_sum(freq.begin(), freq.end(), freq.begin());

        for(long long i=0; i<n; i++){
            cout<<freq[i]*b[i]+partial[i]<<" ";
        }
        cout<<endl;

    }

    return 0;
}