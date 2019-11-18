#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    scanf ("%d %d", &n, &m);
    vector < int > a (n);
    for (int & x : a) scanf ("%d", & x);
    sort (a.begin(), a.end());
    vector < ll > p (n);
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    vector < vector < ll > > sums (m);
    for (int i = 0; i < n; i++) {
        if (sums[i%m].size() == 0) {
            sums[i%m].push_back (a[i]);
        } else {
            sums[i%m].push_back (a[i] + sums[i%m].back());
        }
    }
    ll prev_ans = 0;
    for (int i = 0; i < n; i++) {
        ll ans = prev_ans + sums[i%m][i/m];
        cout << ans << " ";
        prev_ans = ans;
    }
    cout << endl;
    return 0;
}
