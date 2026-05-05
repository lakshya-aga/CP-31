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
        
        long long n, m, k;
        cin>>n>>m>>k;
        vector<long long> b(n);
        for(long long i=0; i<n; i++){
            cin>>b[i];
        }
        for(int i=0; i<n-1; i++){
            b[i] = b[i+1] - b[i];
        }
        b[n-1]=0;
        int count = m;
        int total_length = m;
        sort(b.begin(), b.end());
        for(int i=1; i<n; i++){
            if(count<=k){
                break;
            }
            count--;
            total_length+=b[i]-1;
        }
        
        cout<<total_length<<endl;

        
    }
}