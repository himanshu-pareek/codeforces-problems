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
    int n, c;
    cin >> n >> c;
    vector < int > a (n);
    vector < int > b (n);
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    vector < vector < ll > > dp (n + 1, vector < ll > (2));
    dp[1][0] = 0; dp[1][1] = c;
    cout << 0;
    for (int i = 2; i <= n; i++){
        dp[i][0] = min (dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1]);
        dp[i][1] = min (dp[i - 1][0] + c + b[i - 1], dp[i - 1][1] + b[i - 1]);
        cout << " " << min (dp[i][0], dp[i][1]);
    }
    cout << endl;
}
