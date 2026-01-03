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
        long long n;
        cin>>n;
        int upper = pow(2, n);
        int lower = pow(2,n-1);
        vector<int> done;
        for(int i=n; i>=0; i--)
            {
                cout<<pow(2, i)-1<<" ";
                done.push_back(pow(2, i)-1);
            }
        for(int i=0; i<pow(2,n)-1; i++)
        if(find(done.begin(), done.end(), i)==done.end())
        cout<<i<<" ";

        
        cout<<"\n";

    }

    return 0;

}