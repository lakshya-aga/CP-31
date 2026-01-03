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
        long long n,q;
        cin>>n;
        cin>>q;
        vector<long long> a(n);        
        
        for(int i=0; i<n; i++)
        cin>>a[i];
        
        vector<int> x(q);
        
        for(int i=0; i<q; i++)
        cin>>x[i];

        vector<int> powers(31);

        for(int i=0; i<=30; i++)
        powers[i] = pow(2, i);

        int prev_min = 31;
        vector<vector<pair<int,int>>> divisible(31);
        

        for(int i = 0; i<q; i++)
        {
            if(x[i]<prev_min)
            {
                for(int k=0; k<n; k++)
                {
                    long long val =  pow(2, x[i]);
                    if(a[k] % val==0)
                    {
                        a[k]+=val/2;
                    }
                }

            }
            prev_min = min(prev_min, x[i]);
        }
        

        for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
        cout<<endl;
        
    }

    return 0;

}