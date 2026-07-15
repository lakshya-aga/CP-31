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
        
        if(n%2==0)
        {
            for(int i=n; i>=1; i--)
            cout<<i<<" ";
            cout<<endl;
            continue;
        }

        for(int i=n-1; i>=1; i--)
        cout<<i<<" ";
        cout<<n<<endl;
        cout<<endl;
    }

    return 0;
}

// 1 2 3
// 2 1 3
// 2 2 9


// 1 2 3 4
// 3 2 1 4


// 1 2 3 4 5
// 4 3 2 1 5
// 4 6 6 4 25
