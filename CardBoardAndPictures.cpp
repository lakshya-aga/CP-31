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
        ll c;
        cin >> n >> c;

        vector<ll> s(n);
        ll sum = 0, sumsq = 0;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            sum += s[i];
            sumsq += s[i] * s[i];
        }

        // Use long double to avoid overflow
        long double S = sum;
        long double N = n;
        long double C = c;

        long double discriminant = S*S - N*(sumsq - C);
        long double x = (sqrt(discriminant) - S) / N;

        cout << (ll)x/2 << "\n";
    }
}
