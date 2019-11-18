#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void printMatrix (vector < vector < int > > &a) {
    for (vector < int > vec : a) {
        for (int x : vec) {
            cout << x << "\t";
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
}

class LRU {
    map < int, int > timeToKey;
    set < int > keys;
    int N, size, time;
    public:
    LRU (int capacity) {
        timeToKey.clear();
        keys.clear();
        N = capacity;
        size = time = 0;
    }
    void put (int key) {
        if (keys.find (key) != keys.end()) {
            return;
        }
        if (size == N) {
            auto it = timeToKey.begin();
            int k = it -> second;
            timeToKey.erase (it -> first);
            keys.erase (k);
            size--;
        }
        timeToKey[time ] =key;
        keys.insert (key);
        size++;
        time++;
    }
    void printKeys () {
        cout << timeToKey.size() << endl;
        for (auto it = timeToKey.rbegin(); it != timeToKey.rend(); it++) {
            cout << (it -> second) << " ";
        }
        cout << endl;
    }
};

bool solve (vector < vector < int > > &a, int n) {
    // printMatrix (a);
    int x = 0, y = 1;
    bool rowChange = false;
    while (y <= n) {
        // cout << rowChange << " " << x << " " << y << endl;
        switch (a[x][y]) {
            case 0:
                if (rowChange) {
                    return false;
                }
                y++;
                break;
            case 1:
                if (rowChange) {
                    y++;
                } else {
                    x = 1 - x;
                }
                rowChange = !rowChange;
        }
    }
    return x == 1;
}

int main() {
	int q, n;
    string s;
    cin >> q;
    char pipe[7];
    for (int i = 1; i <= 2; i++) pipe[i] = 0;
    for (int i = 3; i <= 6; i++) pipe[i] = 1;
    while (q--) {
        cin >> n;
        vector < vector < int > > pipes (2, vector < int > (n + 2, 0));
        cin >> s;
        for (int i = 0; i < n; i++) {
            pipes[0][i + 1] = pipe[s[i] - '0'];
        }
        cin >> s;
        for (int i = 0; i < n; i++) {
            pipes[1][i + 1] = pipe[s[i] - '0'];
        }
        if (solve (pipes, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

