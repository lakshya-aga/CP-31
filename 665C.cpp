#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

#include <iomanip>

int main(){

    string s;
    cin>>s;
    for(int i=1; i<s.length(); i++){
        if(s[i] == s[i-1]){
            s[i] = max(s[i-1], s[i+1]) +1;
            if(s[i]>'z'){
                s[i] = min(s[i-1], s[i+1]) - 1;
            }
            if(s[i]<'a'){
                s[i] = 'b';
            }
        }
    }
    cout<<s<<endl;

}