#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

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

int main() {
	int n, k, x;
    cin >> n >> k;
    LRU* lru = new LRU (k);
    while (n--) {
        cin >> x;
        lru -> put (x);
        // lru -> printKeys();
    }
    lru -> printKeys();
    return 0;
}

