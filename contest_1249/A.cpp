#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve () {
    int n, x;
    cin >> n;
    vector < int > count (101, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        count[x] = 1;
    }
    for (int i = 1; i < 100; i++) {
        if (count[i] & count[i + 1]) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    int q, n;
    cin >> q;
    while (q--) {
        solve ();
    }
}
