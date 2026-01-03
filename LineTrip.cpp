#include <iostream>
#include <vector>
using namespace std;
int main(){
    int num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        int n,x;
        cin>>n;
        cin>>x;
        vector<int> arr(n);
        int curr_max=-1;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(curr_max==-1)
            curr_max=arr[i];
            else
            curr_max = max(curr_max, arr[i]-arr[i-1]);
        }
        curr_max = max(curr_max, (x-arr[n-1])*2);
        cout<<curr_max<<endl;
    }
    return 0;
}