#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
    int num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        int n,k;
        cin>>n;
        cin>>k;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> sum_a(n);
        
        vector<int> sb(n);
        for(int i=0; i<n; i++)
        cin>>a[i];
        partial_sum(a.begin(), a.end(), sum_a.begin());
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
            if(i)
                b[i] = max(b[i], b[i-1]);
        }
        int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            sb[i] = k>i? sum_a[i]+(k-i-1)*b[i]:0;
            ans = max(ans, sb[i]);
        }
        cout<<ans<<endl;
    }

    return 0;

}