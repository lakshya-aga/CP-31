#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    string s;
    cin>>s;
    long long t;
    cin>>t;
    unordered_map<char, long long> freq;
    for(auto i: s){
        freq[i]++;
    }
    while(t--){
        long long a, b;
        cin>>a>>b;
        if(a>b){
            b=a+b;
            a=b-a;
            b=b-a;
        }
        long long diff = b-a;
        long long target = -freq['+']*a + freq['-']*a;
        // cout<<target<<" "<<freq['+']<<" "<<freq['-']<<endl;
        if((diff == 0 || (target%diff) == 0)
        && (target>=-freq['-']*diff) && (target<=diff*freq['+'])){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}