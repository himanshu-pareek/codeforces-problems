#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
    int t, a, b, c, d, k;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> k;
        int pens = (a + c - 1) / c;
        int pencils = (b + d - 1) / d;
        if (pens + pencils > k) {
            cout << -1 << endl;
        } else {
            cout << pens << " " << pencils << endl;
        }
    }
    return 0;
}
