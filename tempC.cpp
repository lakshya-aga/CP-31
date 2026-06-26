#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

int count_digits(int n){
    int ans = 0;
    while(n!=0){
        n=n/10;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int a, n;
        cin>>a;
        cin>>n;

        vector<int> d(n);
        for(auto &i: d)
        cin>>i;

        sort(d.begin(), d.end());

        
        auto digits = count_digits(a);
        // d+1

        auto min_dig = accumulate(d.begin(), d.end(), d[0], less_equal<>());
        auto max_dig = accumulate(d.begin(), d.end(), d[0], greater_equal<>());
        
        string temp1('1', digits+1);
        string temp2('1', digits-1);

        auto ans1 = stoll(temp1)*min_dig-n;
        auto ans2 = n - stoll(temp2)*max_dig;

        

    }

    return 0;
}