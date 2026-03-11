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
        int prev_s = -1;
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 's'){
                prev_s = i;
            }
            else if(s[i] == 'u' && prev_s == -1){
                count = count+1;
                prev_s = i;
            }
            else if(s[i]=='u')
            {
                count+= s[i + (i-prev_s)]=='s' ? 0 : 1;
                s[i + (i-prev_s)]='s';
            }
        }
        cout<<count<<endl;
    }
}