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
        int a, b;
        cin>>a>>b;
        vector<int> a_bits(19, 0);
        vector<int> b_bits(19, 0);
        for(int i=0; i<=18; i++){
            if(a & (1<<i)) a_bits[i]=1;
            if(b & (1<<i)) b_bits[i]=1;

        }
    }

    return 0;
}