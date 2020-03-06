#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void max_self (int & a, int b) {
    if (a < b) a = b;
}

void solve() {
    int n;
    scanf ("%d", &n);
    vector < int > a (n);
    for (int & x : a) scanf ("%d", & x);
    vector < int > left (n, -1);
    vector < int > right (n, n);
    stack < int > s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push (i);
    }
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push (i);
    }
    vector < int > ans (n + 1, 0);
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        max_self (ans[len], a[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        max_self (ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        printf ("%d ", ans[i]);
    }
    printf ("\n");
}

int main() {
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
