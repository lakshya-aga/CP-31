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
        int n, k;
        cin>>n;
        vector<long long> a(n);        
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int min_idx = 0;
        int min_val = a[0];
        int max_factor = 1;
        vector<long long> ans(n);
        for(int i=0; i<n; i++, max_factor++)
        {
            while(max_factor>min_val)
            {
                min_idx++;
                min_val = a[min_idx];
                max_factor--;
            }
            ans[i] = i+1 - min_idx;
        }
        for(auto a: ans)
        cout<<a<<" ";
        cout<<endl;
        
        
    }
        

    

    return 0;

}