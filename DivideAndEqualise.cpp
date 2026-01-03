#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

map<long long, int> divisors;

template <typename T>
void prime_factors(T n)
{
    int i = 2;
    while(i*i<=n)
    {
        while(n%i==0)
        {
            n=n/i;
            divisors[i]++;
        }
        i++;
    }
    if(n>1)
    divisors[n]++;
}
int main(){
    long long num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        divisors.clear();
        int n, k;
        cin>>n;
        vector<long long> a(n);        
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        long long curr = 1;
        for(int i=0; i<n; i++)
        {
            prime_factors(a[i]);
        }
        bool flag = true;
        for(auto pair: divisors)
        {
            if(pair.second%n!=0)
            {
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
            else
            continue;
        }
        if(flag)
        cout<<"YES"<<endl;
        
    }
        

    

    return 0;

}