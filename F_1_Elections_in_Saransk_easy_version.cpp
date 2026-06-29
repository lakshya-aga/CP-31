#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
long long MOD= (1e9+7);
vector<long long> iter_primes;

void solve(){
    long long n, x;
    cin>>n>>x;
    vector arr(n, 0);
    for(auto &i: arr) cin>>i;
    
    unordered_map<long long, long long> prime_count;
    
    for(long long i=0; i<n; i++)
    {
        auto curr = arr[i];
        for(auto prime: iter_primes){
            if(prime*prime > curr)
            break;
            while(curr>1 && curr%prime==0 ){
                curr=curr/prime;
                prime_count[prime]++;
            }
        }
        if (curr > 1) prime_count[curr]++;     
    }
    long long ans = 1;
    for(auto item: prime_count){
        ans*=(item.second+1);
        ans = ans%MOD;
    }
    cout<<ans<<endl;


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> primes(5*1e5+1, 1);
    primes[1]=0;
    primes[0]=0;

    for(long long i=2; i<5*1e5+1; i++)
    {
        if(!primes[i])
        continue;
        for(long long j=i+i; j<5*1e5+1; j+=i){
            primes[j]=0;
        }
    }

    for(long long i=2; i<5*1e5+1; i++)
    if(primes[i])
    iter_primes.push_back(i);

    primes.clear();

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}