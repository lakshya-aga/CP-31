/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
   long long n, h, k;
   long long t;
   cin>>t;
   while(t--){
        cin>>n>>h>>k;
        vector<long long> arr(n);
        for(long long i=0; i<n; i++)
        cin>>arr[i];
        long long mag = 0;
        mag = accumulate(arr.begin(), arr.end(), mag);
        long long ans = (h/mag)*(k+n);
        h = h%mag;
        if(h%mag==0){
            ans = ans-k;
            cout<<ans<<endl;
            continue;
        }
        vector<long long> right_max(n);
        reverse(arr.begin(), arr.end());
        
        inclusive_scan(arr.begin(), arr.end(), right_max.begin(), [](long long a, long long b){ return max(a, b);});
        reverse(right_max.begin(), right_max.end());
        reverse(arr.begin(), arr.end());
        right_max.push_back(0);
        vector<long long> left_min(n);
        inclusive_scan(arr.begin(), arr.end(), left_min.begin(), [](long long a, long long b){ return min(a, b);});

        vector<long long> cumsum(n);
        inclusive_scan(arr.begin(), arr.end(), cumsum.begin(), [](long long a, long long b){ return a+b;});
        // for(auto i: right_max)cout<<i<<" "; cout<<endl;
        // for(auto i: left_min)cout<<i<<" "; cout<<endl;
        // for(auto i: cumsum)cout<<i<<" "; cout<<endl;
        // cout<<"temp:h "<<h<<endl;
        // cout<<"temp:ans "<<ans<<endl;
        for(long long i=0; i<n; i++){
            if(cumsum[i]-left_min[i]+max(right_max[i+1], left_min[i])>=h){
                cout<< ans+i+1 << endl;
                break;
            }
        }
        
   }
}