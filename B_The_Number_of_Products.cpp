#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <ranges>
using namespace std;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>0)
        arr[i]=1;
        else
        arr[i]=-1;
    }
    vector<long long> cumprod(n);
    vector<long long> count_p_b4(n);
    vector<long long> count_n_b4(n);
    
    partial_sum(arr.begin(), arr.end(), cumprod.begin(), [](auto a, auto b){return a*b;});
    long long curr = 1;
    long long ans = 0;
    for(long long i = 0 ; i<n; i++){
        count_p_b4[i]=curr;
        count_n_b4[i]=i+1-curr;
        if(cumprod[i]==1)
        curr++;
        if(cumprod[i]==1)
        ans+=count_p_b4[i];
        else
        ans+=count_n_b4[i];

    }
    cout<<n*(n+1)/2-ans<<" "<<ans<<endl;

    return 0;
}