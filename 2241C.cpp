// 2241C
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count_swich = 0;
        for(int i=1; i<n; i++){
            if(s[i]!=s[i-1])
            count_swich++;
        }
        if(count_swich!=1){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
        
    }
        

    return 0;
}