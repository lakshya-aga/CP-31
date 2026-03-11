#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;



int main(){
    long long num_cases;
    // cout<<"input"<<endl;
    cin>>num_cases;
    while(num_cases--)
    {
        long long k, x;
        cin>>k>>x;
        int count = 0;
        if(x>=k*k)
        {
            cout<<2*k-1<<endl;
        }
        else if(x<=k*(k+1)/2)
        {
            cout<<ceil((sqrt(1+8*x)-1)/2)<<endl;
        }
        else
        {
            x = x-k*(k+1)/2;
            // long double D = (k+1)*(k+1L) + 4.0L * ((long double)x);
            // long long y = (long long)ceill((sqrtl(D) - 1.0L - k ) / (2.0L*(k+1)));
            

            long double D = (2.0L*k - 1)*(2.0L*k - 1) - 8.0L*x;
            long long y = ceill(((2.0L*k - 1) - sqrtl(D)) / 2.0L);
            
            cout << (k + y) << endl;
        }

    }    
    return 0;

}

// (k-1)*k - y*(y+1) >= x
// y = ceil(-0.5 + sqrt(1 + 4 * ((k - 1) * k - x)) / 2);