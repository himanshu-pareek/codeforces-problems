#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm (ll a, ll b) {
    ll gcd_ab = __gcd (a, b);
    return (a * b) / gcd_ab;
}

bool isPossible (vector < ll > &p, ll n, ll x, ll a, ll y, ll b, ll ab, ll k, ll m) {
    ll i = 0;
    ll money = 0;
    for (ll j = ab; j <= m; j += ab) {
        money += (p[i++] * (x + y));
    }
    for (ll j = b; j <= m; j += b) {
        if (j % ab != 0) {
            money += y * p[i++];
        }
    }
    for (ll j = a; j <= m; j += a) {
        if (j % ab != 0) {
            money += x * p[i++];
        }
    }
    return money >= k;
}

int main() {
    ll q, n, x, y, a, b;
    ll k;
    cin >> q;
    while (q--) {
        cin >> n;
        vector < ll > p (n);
        for (ll i = 0; i < n; i++) {cin >> p[i]; p[i] /= 100; }
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        if (x > y) {
		    a^=b^=a^=b;
		    x^=y^=x^=y;
		}
        ll ab = lcm (a, b);
        sort (p.begin(), p.end());
        reverse (p.begin(), p.end());
        ll low = 1, high = n;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (isPossible (p, n, x, a, y, b, ab, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (low > n) {
            low = -1;
        }
        cout << low << endl;
    }
}
