#include <iostream>
using namespace std;

int main() {
    int q, n, ans;
    cin >> q;
    while (q--) {
        cin >> n;
        if (n <= 4) {
            ans = 4 - n;
        } else {
            ans = n % 2;
        }
        cout << ans << endl;
    }
    return 0;
}
