#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int curr=0;
        int ans = 1;
        vector<int> color;
        int previous_curr=0;
        int first_color = false;
        int second_color = false;
        for(auto i: s){
            if(i=='('){
                previous_curr=curr++;
            }
            else{
                previous_curr=curr--;
            }
            if(curr<0 || previous_curr<0 && curr==0){
                second_color = true;
                color.push_back(2);
            }
            else{
                first_color = true;
                color.push_back(1);
            }
        }
        if(curr!=0){
            cout<<-1<<endl;
            continue;
        }
        if(first_color && second_color)
        {cout<<2<<endl;ans=2;}
        else
        {cout<<1<<endl;ans=1;}
        for(auto i: color){
            if(ans==1)
            cout<<1<<" ";
            else
            cout<<i<<" ";
        }
        cout<<endl;

    }
}

