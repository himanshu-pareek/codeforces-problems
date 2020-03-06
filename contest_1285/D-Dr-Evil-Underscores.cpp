#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct node {
	node* next[2];
};

node* createNode () {
	return new node();
}

node* insert (node* root, int x) {
	node* r = root;
	//cout << x << endl;
	//cout << "bits: ";
	for (int i = 31; i >= 0; i--) {
		int bit = (x >> i) & 1;
		//cout << bit << " ";
		if (!(r -> next)[bit]) {
			(r -> next)[bit] = createNode();
		}
		r = (r -> next)[bit];
	}
	//cout << endl;
	return root;
}

int search (node* root, int bit) {
	if (!root) return 0;
	int it = 0;
	if ((root -> next)[0] && (root -> next)[1]) {
		it = 1 << bit;
	} else if (!(root -> next)[0] && !(root -> next)[1]) {
		return 0;
	}
	vector < int > vals (2);
	for (int b = 0; b < 2; b++) {
		if ((root -> next)[b]) {
			vals[b] = search ((root -> next)[b], bit - 1);
		} else {
			vals[b] = INT_MAX;
		}
	}
	return it + min (vals[0], vals[1]);
}
	

int main() {
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	node* root = createNode();
	for (int x : a) {
		root = insert (root, x);
	}
	int ans = search (root, 31);
	cout << ans << endl;
	return 0;
}

