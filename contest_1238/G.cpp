#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct friend {
    int time, maxAmount, rate;
};

bool sortFriends (const friend& f1, const friend& f2) {
    return f1.time > f2.time;
}

int main() {
    int q, n, m, c, c0;
    cin >> q;
    while (q--) {
        cin >> n >> m >> c >> c0;
        vector < friend > friends (n);
        for (int i = 0; i < n; i++) {
            cin >> friends[i].time >> friends[i].maxAmount >> friends[i].rate;
        }
        ll maxPrice = 0;
        bool possible = true;
        int required = 0, prevTime = m;
        for (int i = 0; i < n; i++) {
            if (friends[i].time >= m) continue;
            int requirement = required + (prevTime - friends[i].time);
            if (requirement > c ||  requirement )
        }
    }
}