#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
     int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        string s;
        cin >> s;
        s = s+s;
        int max_cont = 0;
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '1') {
                count++;
            } else {
                max_cont = max(max_cont, count);
                count = 0;
            }
            max_cont = max(max_cont, count);
        }
        if(max_cont>s.length()/2){
            cout<<(s.length()/2)*(s.length()/2)<<endl;
            continue;
        }
        if(max_cont%2==0){
            cout<<(long)max_cont/2ll * (max_cont/2ll+1)<<endl;
        }
        else{
            cout<<(long)(max_cont/2ll+1)*(max_cont/2ll+1)<<endl;
        }
    }
}