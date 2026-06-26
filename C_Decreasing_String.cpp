#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;
int t;
void solve() {
    string str;
    ll pos;
    cin>>str;
    cin>>pos;
    pos--;
    auto curr_len = str.length();
    str = str + 'Z';
    vector<char> s;
    for(auto i: str){
        while(s.size() && s.back()>i && pos>=curr_len){
            pos-=curr_len; //3
            curr_len--; //2
            s.pop_back();
        }
        s.push_back(i);
    }
    s.pop_back();
    // if(pos>=s.size() && pos<0)
    // cout<<"Out of bounds"<<endl;
    // if(t<=3)
    cout<<s[pos];
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
