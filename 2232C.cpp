#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // your code here
    int t;
    cin>>t;
    while(t--){
        int n, x, s;
        cin>>n>>x>>s;
        string u;
        cin>>u;
        unordered_map<char, int> freq;
        for(auto i: u){
            freq[i]++;
        }
        int ET=x, NETS=0, I=freq['I'], E=freq['E'], A=freq['A'];
        int prev_A = 0;
        int ans = 0;
        for(auto i: u){
            switch(i){
                case 'E': E--;
                            if(NETS){
                                NETS--;
                                ans+=1;
                            }
                            else if (prev_A>0 && ET){ // sit the first seen A into I
                                prev_A--;
                                NETS--;
                                NETS=NETS+s-1;
                                ans+=2;
                            }
                               break; 
                case 'I':
                if(ET){
                    ET--;
                    I--;
                    NETS+=s-1;
                    ans+=1;
                }
                               break; 

                case 'A':       prev_A++;
                if(I+E+A==n){
                    prev_A--;
                    ET--;
                    A--;
                    NETS+=s-1;
                    ans+=1;
                }

                                break; 
            }
        }
        NETS+ET*s;
        ans+=min(NETS+ET*s, prev_A);
        cout<<ans<<endl;

    }

    return 0;
}