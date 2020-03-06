#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct SegmentTreeNode {
	int numMatched, opened, closed;
	
	void assignLeafValue (char value) {
		numMatched = 0;
		if (value == '(') {
			opened = 1; closed = 0;
		} else {
			opened = 0; closed = 1;
		}
	}
	
	void merge (SegmentTreeNode & left, SegmentTreeNode & right) {
		int temp = min (left.opened, right.closed);
		numMatched = left.numMatched + right.numMatched + temp;
		opened = left.opened + right.opened - temp;
		closed = left.closed + right.closed - temp;
	}
	
	int getValue () {
		return numMatched;
	}
};

template < class T, class V >
class SegmentTree {
	vector < SegmentTreeNode > tree;
	int N;
	
	private:
	int getSegmentTreeSize (int n) {
		int sz = 1;
		for (;sz < N; sz <<= 1);
		return sz << 1;
	}
	
	void buildTree (vector < T > & arr, int low, int high, int pos) {
		if (low == high) {
			tree[pos].assignLeafValue (arr[low]);
			return;
		}
		int mid = low + (high - low) / 2;
		buildTree (arr, low, mid, 1 + (pos << 1));
		buildTree (arr, mid + 1, high, 2 + (pos << 1));
		tree[pos].merge (tree[1 + (pos << 1)], tree[2 + (pos << 1)]);
	}
	
	void update (int index, T value, int low, int high, int pos) {
		if (index < low || index > high) return;
		if (low == high) {
			tree[pos].assignLeafValue (value);
		}
		int mid = low + (high - low) / 2;
		update (index, value, low, mid, 1 + (pos << 1));
		buildTree (index, value, mid + 1, high, 2 + (pos << 1));
		tree[pos].merge (tree[1 + (pos << 1)], tree[2 + (pos << 1)]);
	}
	
	SegmentTreeNode query (int left, int right, int low, int high, int pos) {
		if (left <= low && right >= high) {
			return tree[pos];
		}
		
		int mid = (low + high) / 2;
		if (left > mid) {
			return query (left, right, mid + 1, high, 2 + (pos << 1));
		} else if (right <= mid) {
			return query (left, right, low, mid, 1 + (pos << 1));
		}
		
		SegmentTreeNode leftResult = query (left, right, low, mid, 1 + (pos << 1));
		SegmentTreeNode rightResult = query (left, right, mid + 1, high, 2 + (pos << 1));
		SegmentTreeNode result;
		result.merge (leftResult, rightResult);
		return result;
	}
	
	public:
	SegmentTree (vector < T > & arr) {
		N = arr.size();
		tree.resize (getSegmentTreeSize(N));
		buildTree (arr, 0, N - 1, 0);
	}
	
	~SegmentTree () {
		tree.resize (0);
	}
	
	V query (int left, int right) {
		SegmentTreeNode result = query (left, right, 0, N - 1, 0);
		return result.getValue();
	}
	
	void update (int index, T value) {
		update (index, value, 0, N - 1, 0);
	}
};

int main() {
	string s;
	cin >> s;
	const int n = (int) s.size();
	vector < char > a;
	for (char c : s) a.push_back (c);
	SegmentTree < char, int > st (a);
	int m, l, r;
	scanf ("%d", &m);
	while (m--) {
		scanf ("%d %d", &l, &r);
		l--; r--;
		printf ("%d\n", 2 * st.query (l, r));
	}
	return 0;
}
