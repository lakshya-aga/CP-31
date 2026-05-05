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

    long long t;
    cin>>t;
    while(t--){
        
        long long n, x, y;
        cin>>n>>x>>y;
        vector<long long> a(n);
        int parity = 0;
        for(long long i=0; i<n; i++){
            cin>>a[i];
            parity = (parity+a[i])%2;
        }
        if((x+parity)%2 == y%2)
        cout<<"Alice"<<endl;
        else
        cout<<"Bob"<<endl;       
    }
}