#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <stack>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> st;
    for(auto i: s){
        if(st.empty())
        {
            st.push(i);
            continue;
        }
        auto top = st.top();
        if(i==top){
            st.pop();
            if(i=='1') st.push('0');
            else st.push('1');
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}