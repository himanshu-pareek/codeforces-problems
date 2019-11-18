#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

vector < ll > powers (40, 0);

void solve () {
    ll n; cin >> n;
    // cout << n << endl;
    ll m = n;
    vector < int > counts (40, 0);
    int power = 39;
    while (n > 0) {
        if (n >= powers[power]) {
            counts[power]++;
            n -= powers[power];
        } else {
            power--;
        }
    }
    power = -1;
    bool valid = true;
    for (int i = 39; i >= 0; i--) {
        if (counts[i] > 1) {
            power = i;
            valid = false;
            break;
        }
    }
    if (valid) {
        cout << m << endl; return;
    }
    ll ans = 0;
    int i;
    for (i = power + 1; i < 40; i++) {
        if (counts[i] == 0) {
            ans = powers[i]; break;
        }
    }
    for (; i < 40; i++) {
        if (counts[i] > 0) {
            ans += powers[i];
        }
    }
    cout << ans << endl;
}

int main() {
    powers[0] = 1;
    for (int i = 1; i < 40; i++) {
        powers[i] = powers[i - 1] * 3;
        // cout << powers[i] << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        solve ();
    }
}
