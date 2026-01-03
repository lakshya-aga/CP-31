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
    map<int, int> lookup;
    for(long long i = 2; i<=20; i++)
    {
        for(long long j = 2; j<=1e6; j++)
        {
            lookup[(pow(j, i+1)-1) /( j-1)]++;
        }
    }
    while(num_cases--)
    {
        int n, k;
        cin>>n;

        if(lookup[n])
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
    }
    return 0;

}