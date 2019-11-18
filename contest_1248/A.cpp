#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main() {
    int t, m, n, p, q;
    cin >> t;
    while (t--) {
        cin >> n;
        int countp = 0, countq = 0;
        for (int i = 0; i < n; i++) {
            cin >> p;
            countp += (p % 2);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> q;
            countq += (q % 2);
        }
        ll ans = (ll) countp * (ll) countq;
        countp = n - countp; countq = m - countq;
        ans += (ll) countp * (ll) countq;
        cout << ans << endl;
    }
}