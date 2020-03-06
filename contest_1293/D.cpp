#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18 + 5;

int main() {
	ll x0, y0, ax, ay, bx, by;
	scanf ("%lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by);
	ll xs, ys, t;
	scanf ("%lld %lld %llld", &x, &ys, &t);
	vector < pair < int, int > > nodes;
	nodes.push_back (make_pair (x0, y0));
	pair < int, int > current = make_pair (x0, y0);
	while (current.first < inf && current.second < inf) {
		if (current.first > (inf - bx) / ax) break;
		if (current.second > (inf - by) / ay) break;
		current.first = ax * current.first + bx;
		current.second = ay * current.second + by;
		nodes.push_back (current);
	}
	
	return 0;
}

