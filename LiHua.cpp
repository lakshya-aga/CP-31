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

        long long n, k;
        cin>>n>>k;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
            {
                if(a[i][j]!=a[n-1-i][n-1-j])
                {
                    k--;
                    a[i][j] = a[n-1-i][n-1-j];
                }
                if(k<0)
                break;
            }
        if(k<0)
        break;}
        
        if(k>=0 && (k%2 == 0 || n%2==1))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
    }

}
