#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

void solve(){
    long long a, n;
    cin>>a>>n;
    vector<long long> options(n);
    for(long long i=0; i<n; i++)
    cin>>options[i];

    sort(options.begin(), options.end());
    string sa = to_string(a);

    long long ans1 = a - options[0];
    long long count_digits = to_string(a).length();

    long long curr = 0;
    for(long long i=0; i<max(count_digits-1, 1ll); i++)
    curr = curr*10 + options.back();
    ans1 = abs(curr-a);
    curr = 0;
    for(long long i=0; i<count_digits+1; i++)
    {
        curr = curr*10 ;
        curr+= (options.size()>1 && options[0]==0 && i==0) ? options[1] : options[0];
    }
    long long ans2 = abs(curr-a);
    curr = 0;
    for(int i=0; i<count_digits; i++)
    curr = curr*10+options.front();    
    
    long long ans = min(ans1, ans2);
    ans = min(ans, abs(curr-a));
    curr=0;
    for(long long i=0; i<count_digits; i++){
        long long dig = (sa[i] - '0');
        long long j;
        bool found=false;
        for(j=0; j<n; j++)
        {
            if(dig == options[j])
            {
                curr = curr*10 + dig;
                found = true;
                // i++;
            }
            if(dig<options[j])
            break;
        }
        if(i==count_digits-1 && found)
        ans = min(ans, abs(curr-a));
        if(found)
        continue;
        // populate with next lowest, then min
        if(j<n)
        {
            long long temp_curr = curr*10+options[j];
            auto temp = i+1;
            for(temp=temp; temp<count_digits; temp++)
            temp_curr = temp_curr*10+options.front();

            ans = min(ans, abs(temp_curr-a));

        }
        if(j>0 && (curr!=0 || options[j-1]!=0))
        {
            long long temp_curr = curr*10+options[j-1];
            auto temp = i+1;
            for(temp=temp; temp<count_digits; temp++)
            temp_curr = temp_curr*10+options.front();

            ans = min(ans, abs(temp_curr-a));

        }
        break;

    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // your code here
    long long t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}


