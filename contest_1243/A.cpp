#include <iostream>
#include <vector> 

using namespace std;

void max_self (int & a, int b) {
	a = max (a, b);
}

void solve () {
	int n, x;
	scanf ("%d", &n);
	vector < int > count (n + 2, 0);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		count[x]++;
	}
	int answer = 0;
	for (int i = n; i >= 1; i--) {
		count[i] += count[i + 1];
		int side = min (i, count[i]);
		max_self (answer, side);
	}
	printf ("%d\n", answer);
}

int main() {
	int k;
	scanf ("%d", &k);
	while (k--) {
		solve();
	}
}

