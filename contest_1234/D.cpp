#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class SegmentTree {
    private:
    vector < vector < int > > tree;
    string s;
    int N;

    void buildTree (string s, int low, int high, int pos) {
        if (low == high) {
            tree[pos][s[low] - 'a']++;
            return;
        }
        int mid = low + (high - low) / 2;
        int left = 2 * pos + 1, right = 2 * pos + 2;
        buildTree (s, low, mid, left);
        buildTree (s, mid + 1, high, right);
        for (int i = 0; i < 26; i++) {
            tree[pos][i] = tree[left][i] + tree[right][i];
        }
    }

    void updateUtil (int index, char c, int low, int high, int pos) {
        if (index < low || index > high) {
            return;
        }
        if (low == high) {
            tree[pos][s[index] - 'a']--;
            tree[pos][c - 'a']++;
            return;
        }
        int mid = low + (high - low) / 2;
        int left = 2 * pos + 1, right = 2 * pos + 2;
        updateUtil (index, c, low, mid, left);
        updateUtil (index, c, mid + 1, high, right);
        for (int i = 0; i < 26; i++) {
            tree[pos][i] = tree[left][i] + tree[right][i];
        }
    }

    vector < int > queryUtil (int l, int r, int low, int high, int pos) {

        if (l <= low && r >= high) {
            return tree[pos];
        }
        if (l > high || r < low) {
            vector < int > temp (26, 0);
            return temp;
        }

        int mid = low + (high - low) / 2;
        int left = 2 * pos + 1, right = 2 * pos + 2;
        vector < int > leftArray = queryUtil (l, r, low, mid, left);
        vector < int > rightArray = queryUtil (l, r, mid + 1, high, right);
        for (int i = 0; i < 26; i++) {
            leftArray[i] += rightArray[i];
        }
        return leftArray;
    }

    void printMatrix () {
        cout << "------------------------------------------------------" << endl;
        for (int i = 0; i < 2 * N - 1; i++) {
            cout << i << " => [ ";
            for (int j = 0; j < 26; j++) {
                cout << tree[i][j] << ",";
            } 
            cout << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }
    public:
    SegmentTree (string s) {
        this -> s = s;
        const int n = s.length();
        N = ceil(log2 (n));
        N = 1 << N;
        if (N < n) {
            N <<= 1;
        }
        // cout << n << " " << N << endl;
        tree.resize (2 * N - 1, vector < int > (26, 0));
        // printMatrix();
        buildTree (s, 0, n - 1, 0);
        // printMatrix();
    }

    void update (int index, char c) {
        updateUtil (index, c, 0, s.size() - 1, 0);
        s[index] = c;
        // cout << s << endl;
        // printMatrix ();
    }

    int query (int l, int r) {
        vector < int > ans = queryUtil (l, r, 0, s.size() - 1, 0);
        int count = 0;
        for (int x : ans) {
            count += (x > 0);
        }
        return count;
    }

    
};

int main() {
	string s;
    cin >> s;
    SegmentTree* st = new SegmentTree (s);
    int q, x, y, z;
    char c;
    cin >> q;
    while (q--) {
        cin >> x;
        if (x == 1) {
            cin >> y >> c;y--;
            st -> update (y, c);
        } else {
            cin >> y >> z;
            y--, z--;
            cout << (st -> query (y, z)) << endl;
        }
    }
    return 0;
}

