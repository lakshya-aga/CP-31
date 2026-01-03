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
        int n, k;
        cin>>n>>k;
        vector<int> a(n);        
        map<int, int> complement;
        for(int i=0; i<n; i++){

            cin>>a[i];
            complement[a[i]] = 1;
        }
        int i;
        for(i=0; i<n; i++)
        {
            if(complement[a[i]-k] >= 1)
            {
                cout<<"YES"<<endl;
                break;
            }
        }
        if(i==n)
        cout<<"NO"<<endl;
        

    }

    return 0;

}