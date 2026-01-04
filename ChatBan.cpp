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
            cout<<ceil(sqrt(2*x+(k-1)*(k-1))) + k<<endl;
        }

    }    
    return 0;

}