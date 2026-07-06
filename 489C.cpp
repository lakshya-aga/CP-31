#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s;
    cin>>m>>s;

    if(m==1 && s==0)
    cout<<"0 0"<<endl;
    else
    if(m*9 < s || s<1)
    cout<< -1<< " "<<-1;

    else{
        vector<int> digits_min(m, 0);
        digits_min[0] = 1;

        int curr_sum = 1;
        for(int r = m-1; r>=0; r--){
            if(curr_sum<s){
                digits_min[r] += min(9, s-curr_sum);
                curr_sum+=min(9, s-curr_sum);
            }
            else{
                break;
            }
        }

        for(auto i: digits_min) cout<<i;
        cout<<" ";

        vector<int> digits_max(m, 9); // 99
        int r = m-1;
        curr_sum = 9*m; //18
        while(r>=0 && curr_sum>s){
            digits_max[r] = max(0, digits_max[r]-(curr_sum-s));
            curr_sum -= min(9, (curr_sum-s));
            r--;
        }
        // cout<<"--"<<endl;
        for(auto i: digits_max) cout<<i;
        // cout<<"--"<<endl;

        cout<<"\n";

    }



    return 0;
}