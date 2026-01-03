#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;
int main(){
    long long num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        long long n,k;
        cin>>n;
        vector<int> a(n);        
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        int prefix_sum = 0;
        int prefix_min = 0;
        int max_sum = a[0];
        for(int i=0; i<n; i++)
        {
            if(i && abs(a[i]%2)==abs(a[i-1]%2))
            {
                prefix_sum = 0;
                prefix_min = 0;
            }
            prefix_sum+=a[i];
            max_sum = max(prefix_sum-prefix_min, max_sum);
            prefix_min = min(prefix_sum, prefix_min);

        }
        cout<<max_sum<<endl;
    }

    return 0;

}