#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;

    vector<int> is_prime(1e7+1, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(long long i=2; i<is_prime.size(); i++){
        if(is_prime[i])
        for(int j=2*i; j<is_prime.size(); j+=i)
        is_prime[j] = 0;
    }

    
    // cout<<sqrt(999966000289);
    while(t--){
        long long n;
        cin>>n;
        long long count = 0;
        
        if((long long)sqrt(n)*(long long)sqrt(n)==n && is_prime[(long long)sqrt(n)]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";

        }
    }


    return 0;
}