#include <iostream>
typedef long long ll;
using namespace std;

bool check (ll x, ll y) {
    return x - y > 1;
}

int main()
{
    int t;
    ll x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (check (x, y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
