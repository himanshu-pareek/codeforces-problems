#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct triple {
    int f, s, t;
};

void solve() {
    int n;
    scanf ("%d", &n);
    vector < triple > q(n - 2);
    for (triple & t : q) scanf ("%d %d %d", &(t.f), &(t.s), &(t.t));
    map < pii, vector < int > > m;
    vector < int > count (n + 1, 0);
    for (triple t : q) {
        m[{t.f, t.s}].push_back (t.t);
        m[{t.s, t.t}].push_back (t.f);
        m[{t.t, t.f}].push_back (t.s);
        m[{t.s, t.f}].push_back (t.t);
        m[{t.t, t.s}].push_back (t.f);
        m[{t.f, t.t}].push_back (t.s);
        count[t.f]++; count[t.s]++; count[t.t]++;
    }
    int first;
    int second;
    for (triple t : q) {
        if (count[t.f] == 1) {
            first = t.f;
            if (count[t.s] == 2) {
                second = t.s;
            } else {
                second = t.t;
            }
            break;
        } else if (count[t.s] == 1) {
            first = t.s;
            if (count[t.f] == 2) {
                second = t.f;
            } else {
                second = t.t;
            }
            break;
        } else if (count[t.t] == 1) {
            first = t.t;
            if (count[t.f] == 2) {
                second = t.f;
            } else {
                second = t.s;
            }
            break;
        }
    }
    vector < bool > visited (n + 1, false);
    vector < int > a;
    a.push_back (first);
    a.push_back (second);
    visited[first] = true;
    visited[second] = true;
    n -= 2;
    while (n--) {
        int third;
        for (int t : m[{first, second}]) {
            if (!visited[t]) {
                third = t;
                break;
            }
        }
        a.push_back (third);
        visited[third] = true;
        first = second;
        second = third;
    }
    for (int x : a) {
        printf ("%d ", x);
    }
    printf ("\n");
}

int main() {
    int T;
    // scanf ("%d", &T);
    T = 1;
    while (T--) {
        solve();
    }
}
