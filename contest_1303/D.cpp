#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n; int m;
		cin >> n >> m;
		vector < int > a (m);
		for (int & x : a) {
			scanf ("%d", &x);
		}
		ll sum = 0LL;
		for (int x : a) {
			sum += x;
		}
		if (sum < n) {
			cout << -1 << endl;
			continue;
		}
        vector < int > bits (61, 0);
        for (int x : a) {
            bits[(int)log2 (x)]++;
        }
        int res = 0;
        for (int i = 0; i < 60; i++) {
            if ((n >> i) & 1) {
                if (bits[i] > 0) {
                    bits[i]--;
                } else {
                    while (i < 60 && bits[i] == 0) {
                        i++;
                        res++;
                    }
                    bits[i]--;
                    continue;
                }
            }
            if (i + 1 < 61) {
                bits[i + 1] += bits[i] / 2;
            }
        }
        cout << res << endl;
	}
	return 0;
} 
