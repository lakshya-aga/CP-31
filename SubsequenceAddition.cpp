#include <iostream>
#include <vector>
#include <algorithm>
// #include <numeric>
using namespace std;
int main()
{
    int num_cases;
    cin>>num_cases;
    while(num_cases--)
    {

        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        long long curr = 1;
        for(int i=1; i<n; i++)
        {
            if(curr<a[i])
                break;
            curr+=a[i];
        }
        if(a[0]>1 || curr<a[n-1])
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
        
    }

}