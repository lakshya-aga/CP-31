#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long n, k;
        cin>>n;
        cin>>k;
        long upper_bound = min(long(sqrt(n)), k);
        for(long i = upper_bound; i>=1; i--)
        {
            if(n%i==0){
                if(n/i<=k)
                {cout<<max(n/i, i)<<endl; break;}
                cout<<n/i<<endl;
                break;
            }
        }
    }
}