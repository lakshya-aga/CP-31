#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <bit>
using namespace std;
using namespace std;

void solve(){
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
    size_t k; 
    cin>>n>>k;
    string a;
    string b;
    cin>>a>>b;
    vector<char> chars;
    chars.reserve(11);
    unordered_map<char, int> unique;
    for(int i=0; i<n; i++){
        unique[a[i]]++;
        if(unique[a[i]]==1)
        chars.push_back(a[i]);
    }

    // cout<<chars.size()<<endl;
    k = min(k, chars.size());
    vector<int> curr ;
    long long final_ans = 0;
    for(size_t i=0; i < 1<<chars.size(); i++){
        if(__builtin_popcount(i)!=k)
        continue;
        // cout<<i<<endl;
        curr = vector(27, 0);
        for(int ch=0; ch<chars.size(); ch++){
            if((i & (1<<ch))){
                curr[size_t(chars[ch]-'a')]++;
            }
        }
        // cout<<endl;
        long long ans = 0;
        long long cont = 0;
        for(int i=0; i<n; i++){
            if(a[i]==b[i] || curr[size_t(a[i]-'a')])
            cont++;
            else
            {
                ans+=cont*(cont+1)/2;
                cont = 0;
            }
        }
        ans+=cont*(cont+1)/2;
        final_ans = max(ans, final_ans);
        // cout<<"Current ans:"<<ans<<endl;
    }
    cout<<final_ans<<endl;


    }

    return 0;
}