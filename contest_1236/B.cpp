#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll power (ll n, ll k, ll mod) {
    if (k == 0) return 1;
    ll ans = power (n, k / 2, mod);
    ans = (ans * ans) % mod;
    if (k % 2) {
        ans = (ans * n) % mod;
    }
    return ans;
}

template < typename T>
void printVector (const vector < T > & vec) {
    for (const T x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

template < typename T>
void printMatrix (const vector < vector < T > > & mat) {
    for (const vector < T > vec : mat) {
        printVector (vec);
    }
}

int main() {
    ll m, n;
    cin >> n >> m;
    cout << power (power (2, m, MOD) - 1, n, MOD) << endl;
    return 0;
}
