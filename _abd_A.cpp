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
        string line;
        cin>>line;
        int max_len = 0;
        int curr_len = 0;
        for(int i=0; i<n; i++){
            if(line[i]=='#')
            curr_len++;
            else
            curr_len=0;
            max_len = max(max_len, curr_len);

        }
        cout<<(max_len+1)/2<<endl;
    }

    return 0;
}