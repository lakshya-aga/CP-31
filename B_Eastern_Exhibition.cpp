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
    while(t--){
        long long n;
        cin>>n;
        vector<long long> x(n);
        vector<long long> y(n);

        for(long long i=0; i<n; i++){
            cin>>x[i];
            cin>>y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        long long x_contrib = 1;
        if(n%2 == 0){
            x_contrib = 1+x[n/2]-x[n/2-1];
        }
        long long y_contrib = 1;
        if(n%2 == 0){
            y_contrib = 1+(y[n/2]-y[n/2-1]);
        }
        // cout<<x_contrib<<" "<<y_contrib<<endl;
        cout<<x_contrib*y_contrib<<endl;



    }

    return 0;
}