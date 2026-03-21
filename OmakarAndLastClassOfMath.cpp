#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bool ans = false;
        
        for(int i=1; i<sqrt(n); i++)
        {
            if (n%i==0)
            {
                cout<<n/i*(i-1)<<" "<<n/i*(i-1)<<endl;
                ans = true;
                break;
            }
        }
        if (!ans)
        cout<<n-1<<" "<<1<<endl;

    }
}