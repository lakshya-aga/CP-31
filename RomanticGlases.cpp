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
        vector<long long> a(n);        
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        map<long long, int> lookup;
        long long curr = 0;
        for(int i=0; i<n; i++)
        {
            curr += i%2==0?a[i]:-a[i];
            lookup[curr]+=1;
            if(lookup[curr]==2 || curr==0)
            {
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(lookup[curr]<=1 && curr!=0)
        cout<<"NO"<<endl;
        
    }
        

    

    return 0;

}