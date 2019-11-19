#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
    int n, m;
    scanf ("%d %d", &n, &m);
    vector < int > a (n);
    for (int & x : a) scanf ("%d", & x);
    if (m < n || n < 2) {
        printf ("-1\n");
        return;
    }
    vector < pii > b;
    for (int i = 0; i < n; i++) {
        b.push_back ({a[i], i});
    }
    sort (b.begin(), b.end());
    vector < pii > chains;
    chains.push_back ({b[0].second, b.back().second});
    for (int i = 1; i < n; i++) {
        chains.push_back ({b[i - 1].second, b[i].second});
    }
    vector < pii > extras;
    m -= n;
    while (m--) {
        pii c = chains.back();
        if (c.first == b[0].second) {
            extras.push_back ({b[0].second, b[1].second});
        } else {
            chains.pop_back ();
            extras.push_back ({c.first, b[0].second});
            extras.push_back ({c.second, b[1].second});
        }
    }
    ll cost = 0;
    for (pii p : chains) {
        cost += a[p.first] + a[p.second];
    }
    for (pii p : extras) {
        cost += a[p.first] + a[p.second];
    }
    printf ("%lld\n", cost);
    for (pii p : chains) {
        printf ("%d %d\n", p.first + 1, p.second + 1);
    }
    for (pii p : extras) {
        printf ("%d %d\n", p.first + 1, p.second + 1);
    }
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}
