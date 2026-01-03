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
        cin>>n;
        vector<int> a(n);        
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int i;
        int count = 0;
        int x = 0;
        i = n-1;
        while(x<n)
        {
            if(i>=0 && a[i]==a[n-1])
            {
                x++;
                i--;
                continue;
            }

            count+=1;
            x = x*2;
            i = n-x-1;
            
        }
        cout<<count<<endl;

    }

    return 0;

}