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

    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    cin>>s;
    int r = 1;
    for(int i=1; i<n; i++){
        if(s.compare(i, n-i, s.substr(0, n-i))<0){
            r++;
        }
        else{
            break;
        }
        
    }
    int i=0;
    while(i!=k){
        cout<<s[i%r];
        i++;
    }

    return 0;
}