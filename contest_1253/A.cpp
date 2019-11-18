#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
    int n;
    scanf ("%d", &n);
    vector < int > a(n), b (n);
    for (int & x : a) scanf ("%d", & x);
    for (int & x : b) scanf ("%d ", & x);
    vector < int > diff (n);
    for (int i = 0; i < n; i++) {
        diff[i] = b[i] - a[i];
    }
    bool possible = true;
    int i = 0;
    while (i < n && diff[i] == 0) {
        // if (diff[i] < 0) {
        //     possible = false;
        // }
        i++;
    }
    if (i < n && diff[i] < 0) {
        possible = false;
        cout << "NO" << endl;
        return;
    }
    int d;
    if (i < n) d = diff[i];
    while (i < n && diff[i] == d) {
        i++;
    }
    while (i < n && diff[i] == 0) {
        i++;
    }
    if (i == n) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
