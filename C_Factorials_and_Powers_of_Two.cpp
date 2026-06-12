#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

long long count_ones(long long x){
    long long ans = 0;
    for(long long i=0; (1ll<<i) <= x; i++){
        // cout<<(1ll<<i)<<endl;
        if(1ll<<i & x)
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> powerful_numbers;
    
    long long curr = 6;
    for(long long i=4; curr <= 1e12; i++){
        powerful_numbers.push_back(curr);
        curr=curr*i;
    }
    long long n;
    cin>>n;
    while(n--){
        // long long mask = 0;
        long long x;
        cin>>x;
        

    }

    

    

    return 0;
}