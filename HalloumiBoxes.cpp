#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num_cases;
    cin>>num_cases;
    while(num_cases--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        bool sorted=true;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sorted=sorted && (!i || arr[i]>=arr[i-1]);
        }
        if (k>=2 || sorted)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;


}