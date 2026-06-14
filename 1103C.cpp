#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long a,b,x;
        cin>>a>>b>>x;

        long long ans = abs(a-b);
        long long div_count = 0;
        while(a!=0 || b!=0){
            if(a>b){
                a=a/x;
                div_count++;
                ans = min(ans, div_count+abs(a-b));
            }
            else{
                b=b/x;
                div_count++;
                ans = min(ans, div_count+abs(a-b));
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}