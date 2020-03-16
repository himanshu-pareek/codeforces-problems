#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;
using ull = unsigned long long;

/**
 * Codeforces Round #628 (Div. 2)
 * Contest Link : http://codeforces.com/contest/1325
 * Problem : D [ Ehab the Xorcist ]
 * Problem Link : http://codeforces.com/contest/1325/problem/D
 */

int main() {
    ull u, v;
    cin >> u >> v;
    if (u == v && u == 0) {
        cout << 0 << endl; return 0;
    }
    if (u == v) {
        cout << "1\n" << u << "\n"; return 0;
    }
    if (u > v || ((u&1)^(v&1))) {
        cout << "-1\n"; return 0;
    }
    ull x = (v - u) / 2;
    if (x & u) {
        cout << "3\n" << x << " " << x << " " << u << "\n";
        return 0;
    }
    cout << "2\n" << x << " " << (v - x) << "\n";
    return 0;
}

