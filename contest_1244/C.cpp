#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
    ll n, p, w, d, x, y, z;
    cin >> n >> p >> w >> d;
    for (ll y = 0; y < w; y++) {
    	ll temp = p - (d * y);
    	if (temp < 0) break;
    	if (temp % w) continue;
    	x = temp / w;
    	if (x + y > n) continue;
    	cout << x << " " << y << " " << (n - x - y) << endl;
    	return 0;
    }
    cout << -1 << endl;
    return 0;
}

