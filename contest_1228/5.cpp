#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;

int main () {
    int n, k;
    cin >> n >> k;
    ll dp[n + 1][n + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[0][i] = 1;
    }
    ll k_i = 1;
    for (int i = 1; i <= n; i++) {
        ll k_j = 1, k__j = 1;
        for (int j = 1; j <= n; j++) {
            ll x = (dp[i - 1][j - 1] * ((k_i * k_j) % MOD)) % MOD;
            ll y = ((((k - 1) * dp[i - 1][j]) % MOD) * ((k_j - k__j + MOD) % MOD)) % MOD;
            k__j = (k__j * (k - 1)) % MOD;
            k_j = (k_j * k) % MOD;
            dp[i][j] = (x + y) % MOD;
        }
        k_i = (k_i * k) % MOD;
    }
    cout << dp[n][n] << endl;
    return 0;
}