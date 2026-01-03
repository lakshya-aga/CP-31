#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<char, int> mp;
        int ans = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
            if(mp[s[i]] == 1)
            count++;
            ans+=count;
        }
        cout<<ans<<endl;
    }

    return 0;

}