#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==2){
            cout<<-1<<endl;
        }
        else{
            if(n==1)
            cout<<1<<endl;
            else{
                cout<<1<<" "<<2<<" "<<3<<" ";
                long long curr = 6;
                long long total = curr;
                for(int i=4; i<=n; i++){
                    cout<<curr<<" ";
                    curr = curr+curr;
                }
                cout<<endl;
            }
        }
    }

    return 0;
}