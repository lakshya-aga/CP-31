#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> factors;
        int n_copy = n;
        for(int i=2; i<=sqrt(n); i++)
        {
            while(n%i == 0 && n != 1){
                factors.push_back(i);
                n/=i;
            }
        }
        if(n!=1)
        {
            factors.push_back(n);
            n=1;
        }
        // for(auto i: factors) cout<<i<<",";
        // cout<<endl;

        int factor1 = factors[0];
        int factor2 = 1;
        int factor3 = 1;
        int curr = 1;
        for(int i=1; i<factors.size(); i++){
            curr*=factors[i];
            factor3 = n_copy/factor1/curr;
            if(curr!=factor1 && curr!=factor3 && factor3!=factor1 && factor3!=1){
                factor2 = curr;
                cout<<"YES"<<endl;
                cout<<factor1<<" "<<factor2<<" "<<factor3<<endl;
                break;
            }
        }
        if (factor2==1)
        cout<<"NO"<<endl;
        
    }
}