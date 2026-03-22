#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        arr[i]--;
    }
    
    vector<int> brr(n);
    vector<int> pos_of_exit(n);
    for(int i=0; i<n; i++)
    {
        cin>>brr[i];
        brr[i]--;
        pos_of_exit[brr[i]] = i;
    }

    // for(int i=0; i<n; i++){
    // }
    auto ans = 0;
    int curr_max = -1;
    for(int i=0; i<n; i++)
    {
        curr_max = max(pos_of_exit[arr[i]], curr_max);
        if(curr_max > pos_of_exit[arr[i]])
        ans++;
    }

    cout<<ans<<endl;
}