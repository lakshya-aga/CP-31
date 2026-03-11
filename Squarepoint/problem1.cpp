#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Collect distinct positive values
        set<int> distinctPos;
        bool hasZero = false;
        for (int x : a) {
            if (x > 0) {
                distinctPos.insert(x);
            } else {
                hasZero = true;
            }
        }

        // Base operations = number of distinct positive values
        int ops = (int)distinctPos.size()*2-1;

        // If there's at least one zero, need a Smash
        if (hasZero) ops += 1;

        cout << ops << "\n";
    }

    return 0;
}
