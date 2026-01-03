#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        ll start = 0;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        for(int i=0; i<n; i++)
        cin>>a[i];
        for(int i=0; i<n; i++)
        cin>>b[i];
        for(int i=0; i<n; i++)
        cin>>c[i];

        int idxa=0, idxb=0, idxc=0;
        bool flag=true;
        while(flag && (start!=x))
        {   
            flag = false;
            if(idxa<n && (a[idxa]|x) == x)
            {
                flag = true;
                start = start|a[idxa++];
            }
            if(idxb<n && (b[idxb]|x) == x)
            {
                flag = true;
                start = start|b[idxb++];
            }
            if(idxc<n && (c[idxc]|x) == x)
            {
                flag = true;
                start = start|c[idxc++];
            }


        }
        

        string ans = (start==x)?"YES":"NO";
        cout << ans << "\n";
    }
}
