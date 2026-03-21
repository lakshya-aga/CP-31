#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(){

    using namespace std;
    string s;
    long long count_right = 0, count_left = 0;
    cin>>s;
    // cout<<s<<endl;

    vector<long long> count_left_w;
    vector<long long> count_right_w;
    for(long long i=0; i<s.length(); i++){
        if(s[i]=='v' && i>0 && s[i-1]=='v'){
            count_left++;
        }
            count_left_w.push_back(count_left);
    }
    // for(auto i: count_left_w) cout<<i<<" ";
    // cout<<endl;
    // for(auto i: s) cout<<i<<" ";
    // cout<<endl;
    

    for(long long i=s.length()-1; i>=0; i--){
        if(s[i]=='v' && i != s.length()-1 && s[i+1]=='v'){
            count_right++;
            // count_left_w.push_back(++count_left);
        }
        count_right_w.push_back(count_right);
    }
    reverse(count_right_w.begin(), count_right_w.end());

    // for(auto i: count_right_w) cout<<i<<" ";
    // cout<<endl;
    long long ans = 0;
    for(long long i=2; i<s.length(); i++){
        if(s[i]=='o')
        ans+=count_right_w[i]*count_left_w[i];
    }
    cout<<ans<<endl;
}