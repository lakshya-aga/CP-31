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
        vector<long long> b(n);        
        vector<long long> c(n);  
              
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            cin>>b[i];
            c[i] = a[i] - b[i];
        }
        long long max_num = *max_element(c.begin(), c.end());
        int count = 0;
        for(int i=0; i<n; i++){
            if(c[i] == max_num)
            count++;
        }
        cout<<count<<endl;

        for(int i=0; i<n; i++){
            if(c[i] == max_num)
            cout<<i+1<<" ";
        }
        cout<<endl;


        
    }
        

    

    return 0;

}