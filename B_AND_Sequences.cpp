#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
#define MOD 1000000007
template <typename T>
T factorial(T i){
    T x = 1;
    for(int j=1; j<=i; j++)
    x = (x*(j%MOD))%MOD;
    return x%MOD;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        
        vector<long long> num(n);
       
        for(long long i=0; i<n; i++){
            cin>>num[i];
        }
        unordered_map<int, int> freq;
        for(auto i: num)
        freq[i]++;

        auto full_and = num[0];

        for(int i=1; i<n; i++){
            full_and = full_and & num[i];
        }
        // cout<<freq[full_and]<<endl;
        // cout<<factorial(n-1)<<endl;
        int ans = (((freq[full_and]%MOD)*factorial(n-2))%MOD * (freq[full_and]-1))%MOD;
        // for(auto i : freq){
        //     ans=ans/factorial(i.second);
        // }
        // ans*=factorial(freq[full_and]);
        // ans*=factorial(freq[full_and]-1);
        
        cout<<ans<<endl;
        

    }
}