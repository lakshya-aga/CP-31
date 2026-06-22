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
        long long n;
        cin>>n;
        if(n==10){
            cout<<-1<<endl;
        }
        else{
            if(n%12==10){
                cout<<22<<" "<<n-22<<endl;
            }
            else{
                cout<<n%12<<" "<<n-(n%12)<<endl;
            }
        }
    }
    

    return 0;
}