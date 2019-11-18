#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool compareMonstors (const int& a, const int& b) {
    return a > b;
}

int main() {
    int q, n, r;
    cin >> q;
    while (q--) {
        cin >> n >> r;
        vector < ll > x (n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        sort (x.begin(), x.end(), compareMonstors);
        ll diff = 0;
        ll ans = 0;
        int prev = INT_MAX;
        for (int i = 0; i < n; i++) {
            // cout << x[i] << " --" << endl;
            if (x[i] + diff <= 0) {
                break;
            }
            if (prev == x[i]) {
                continue;
            }
            ans++;
            diff = diff - r;
            prev = x[i];
        }
        cout << ans << endl;
    }
    return 0;
}