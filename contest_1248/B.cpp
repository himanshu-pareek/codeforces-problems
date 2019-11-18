#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector < int > a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    ll sumx = 0, sumy = 0;
    for (int i = 0; i < n / 2; i++) {
        sumx += a[i];
    }
    for (int i = n / 2; i < n; i++) {
        sumy += a[i];
    }
    ll ans = (sumx * sumx) + (sumy * sumy);
    cout << ans << endl;
}