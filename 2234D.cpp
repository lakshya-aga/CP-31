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
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        string s2, s1;
        cin>>n>>k;
        // auto num1 = std::stoi(s, nullptr, 2);
        int cnt_1 = 0;
        int cnt_2 = 0;
        cin>>s1;
        for(auto i: s1) if(i=='1') cnt_1++;
        cin>>s2;
        for(auto i: s2) if(i=='1') cnt_2++;
        int cnt_3 = 0;
        // cout<<s1<<" "<<cnt_1<<endl;
        // cout<<s2<<" "<<cnt_2<<endl;
        for(int i=0; i<n ; i++){
            if((s1[i]=='1' || s2[i]=='1') && (s1[i] != s2[i]))
            {
                // cout<<'1'; 
                cnt_3++;
            }
            // else
            // cout<<'0';
        }
        // cout<<cnt_3<<endl;
        

        // auto num2 = std::stoi(s, nullptr, 2);
        long long num = (pow(2, k)+1);
        long long freq1 = 0;
        long long freq2 = 0;
        long long freq3 = 0;
        freq1 += num/3;
        freq2 += num/3;
        freq3 += num/3;
        if(num%3==1){
            freq3++;
        }
        if(num%3==2){
            freq1++;
            freq2++;
        }
        long long res = 0;
        // for(auto i: freq){
            // cout<<i.first<<" "<<i.second<<endl;
        res+=(freq1*(cnt_1)*(n-cnt_1));
        res+=(freq2*(cnt_2)*(n-cnt_2));
        res+=(freq3*(cnt_3)*(n-cnt_3));
        // }
        cout<<res<<"\n";
    }

    return 0;
}