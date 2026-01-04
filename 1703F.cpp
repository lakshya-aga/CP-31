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
        vector<pair<int, int>> a;        
        for(int i=0; i<n; i++){
            int temp = 0;
            cin>>temp;
            if(temp<i+1)
            a.push_back({temp, i+1});
        }
        sort(a.begin(), a.end());
        long long count = 0;
        for(int i = 0; i<a.size(); i++)
        {
            int idx = lower_bound(a.begin(), a.end(), pair<int, int>{a[i].second+1, 0}) - a.begin();
            count+=a.size()-idx;
        }
        cout<<count<<endl;
    }    
    return 0;

}