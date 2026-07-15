#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

void solve(){
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> segments1start;
    vector<int> segments1last;
    vector<int> segments2start;
    vector<int> segments2last;
    vector<char> good1(n, '1');
    vector<char> good2(n, '0');

    for(int i=0; i<n; i+=2){
        good1[i]='0';
        good2[i]='1';
    }
    int start = 1;
    int last = n;
    for(int i=0; i<n; i++){
        if(s[i] == good1[i]){
            continue;
        }
        else{
            start = i;
            last = i;
            while(i<n && s[i]!=good1[i])
            {
                last++;
                i++;
            }
            segments1start.push_back(start);
            segments1last.push_back(last-1);
            // cout<<start<<" "<<last-1<<endl;
        }
    }
    
    // for(auto i: good1) cout<<i;
    // cout<<endl;
    // for(auto i: good2) cout<<i;
    // cout<<endl;
    for(int i=0; i<n; i++){
        if(s[i] == good2[i]){
            continue;
        }
        else{
            start = i;
            last = i;
            while(i<n && s[i]!=good2[i])
            {
                last++;
                i++;
            }
            segments2start.push_back(start);
            segments2last.push_back(last-1);
            // cout<<start<<" "<<last-1<<endl;
        }
    }

    for(int i=0; i<q; i++){
        int l,r,k;
        cin>>l>>r>>k;

        auto count_segs1 = upper_bound(segments1start.begin(), segments1start.end(), r-1) - segments1start.begin()
                            - (lower_bound(segments1last.begin(), segments1last.end(), l-1) - segments1last.begin());

        // cout<<count_segs1<<":seg1:";
        auto count_segs2 = (upper_bound(segments2start.begin(), segments2start.end(), r-1) - segments2start.begin())
                         -(lower_bound(segments2last.begin(), segments2last.end(), l-1) - segments2last.begin())   ;

        // cout<<count_segs2<<":seg2\n";

        if(min(count_segs1, count_segs2)<=k)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
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