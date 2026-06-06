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
        // cout<<powerful_numbers[powerful_numbers.size()-1]<<" ";
    }
    long long n;
    cin>>n;
    while(n--){
        // long long mask = 0;
        long long x;
        cin>>x;
        // cout<<x;
        // return 0;
        long long ans = count_ones(x);

        // cout<<ans<<endl;
        for(long long mask=0; mask < 1<<15; mask++){
            long long factorial_total = 0;
            long long curr_ans = 0;
            for(long long j=0; j<powerful_numbers.size(); j++){
                if((mask & 1<<j) && powerful_numbers[j]<x){
                    factorial_total = factorial_total + powerful_numbers[j];
                    curr_ans+=1;
                }
            }
            if(factorial_total>x)
            continue;
            curr_ans+=count_ones(x-factorial_total);
            ans = min(ans, curr_ans);
        }
        cout<<ans<<endl;

    }

    

    

    return 0;
}