#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
int main(){
    long long t;
    using namespace std;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(long long i=0; i<n; i++){
            cin>>a[i];
        }
        vector<long long> b(n);
        for(long long i=0; i<n; i++){
            cin>>b[i];
        }
        long long ans = 0;
        for(long long i=0; i<n; i++){
            if(i==0){
                long long curr = gcd(a[i], a[i+1]);
                if(curr<=b[i] && curr!=a[i] && gcd(curr, a[i+1]) == curr)
                {
                    ans++;
                    a[i] = curr;
                }
                continue;
            }
            if(i==n-1){
                long long curr = gcd(a[i], a[i-1]);
                if(curr<=b[i] && curr!=a[i] && gcd(curr, a[i-1]) == curr)
                {
                    ans++;
                    a[i] = curr;
                }
                continue;
            }
            long long curr1 = gcd(a[i], a[i+1]);
            long long curr2 = gcd(a[i], a[i-1]);
            long long curr = lcm(curr1, curr2);
            if(curr<=b[i] && curr!=a[i] && gcd(curr, a[i+1])==curr1 && gcd(curr, a[i-1])==curr2)
            {
                ans++;
                a[i] = curr;
            }
            continue;
        }
        cout<<ans<<endl;

    }
}