#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

#include <iomanip>

int main(){

    long long n, k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    long long curr = 0;
    double ans = 0;
    for(int i=0; i<k; i++){
        curr+=arr[i];
    }
    ans+=curr;
    for(int i=k; i<n; i++){
        curr+=arr[i] - arr[i-k];
        ans+=curr;
    }
    ans = ans*1.0/(n-k+1);
    cout<<std::setprecision(15)<<ans<<endl;
    return 0;

}