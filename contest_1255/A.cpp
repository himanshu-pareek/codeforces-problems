#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
    int a, b;
    scanf ("%d %d", &a, &b);
    int diff = abs (a - b);
    int answer = diff / 5;
    diff %= 5;
    answer += (diff / 2);
    diff %= 2;
    answer += diff;
    printf ("%d\n", answer);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}
