#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int r, g, b;
		scanf ("%d %d %d", &r, &g, &b);
		int x = max ((r + g - b) / 2, 0);
		int y = max ((-r + g+ b) / 2, 0);
		int z = max ((r - g - b) / 2, 0);
		printf ("%d\n", x + y + z);
	}
	return 0;
}
