#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;

bool distinctDigits (int n) {
    int count[10] = {0};
    while (n) {
        count[n%10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (count[i] > 1)
            return false;
    }
    return true;
}

int main () {
    int l, r;
    cin >> l >> r;
    for (int n = l; n <= r; n++) {
        if (distinctDigits (n)) {
            cout << n << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}