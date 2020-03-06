#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1e5 + 5;

vector < int > factors[mx];

vector < int > getFactors (int n) {
	vector < int > fact;
	for (int i = 1; (ll) i * i <= n; i++) {
		if (n % i == 0) {
			fact.push_back (i);
			if (i != n / i) {
				fact.push_back (n / i);
			}
		}
	}
	sort (fact.begin(), fact.end());
	return fact;
}

void solve () {
	int a, b, c;
	cin >> a >> b >> c;
	//for (int x : {a, b, c}) {
		//if (factors[x].empty()) {
			//factors[x] = getFactors (x);
		//}
	//}
	int answer = -1;
	int AA, BB, CC;
	//cout << a << ", " << b << ", " << c << ", " << answer << endl;
	for (int B = 1; B < mx; B++) {
		// find A
		int low = 0, high = (int) factors[B].size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (factors[B][mid] <= a) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		int A = factors[B][high];
		int diffA = a - A;
		if (high + 1 < factors[B].size()) {
			if (factors[B][high + 1] - a < diffA) {
				A = factors[B][high + 1];
				diffA = A - a;
			}
		}
		// find C
		int cbyb = c / B;
		int C = cbyb * B;
		int diffC = c - C;
		if ((cbyb + 1) * B - c < diffC) {
			C = (cbyb + 1) * B;
			diffC = C - c;
		}
		if (answer == -1 || answer > (diffA + abs (b - B) + diffC)) {
			answer = diffA + abs (b - B) + diffC;
			AA = A, BB = B, CC = C;
		}
	}
	cout << answer << endl << AA << " " << BB << " " << CC << endl;
}
	

int main() {
	int t;
	cin >> t;
	for (int i = 1; i < mx; i++) {
		factors[i] = getFactors (i);
	}
	while (t--) {
		solve();
	}
	return 0;
}
