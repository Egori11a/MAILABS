#include<stdio.h>

int abs(int x) {
	if (x < 0)
		return -x;
	else
		return x;
}
int max(int x, int y) {
	if (x >= y)
		return x;
	else
		return y;
}
int min(int x, int y) {
	if (x >= y)
		return y;
	else
		return x;
}
int main() {
	int i = 16;
	int j = 1;
	int l = 15;
	if ((i >= 5 && i <= 15) && (j >= -15 && j <= -5))
		printf("The point is in the right boundaries (0 iteration): i=%d j=%d l=%d", i, j, l);
	else {
		for (int k = 1; k <= 10; k++) {
			int i_new; int j_new; int l_new;
			i_new = abs(k - 15) - min(i / 3, (j + l) % 10) - 20;
			j_new = -(j + k) / 5 + abs((i * l) % 8);
			l_new = max((i + j) % 15, (l + k) % 14);
			i = i_new;
			j = j_new;
			l = l_new;
			if ((i >= 5 && i <= 15) && (j >= -15 && j <= -5)) {
				printf("The point is in the right boundaries: i=%d j=%d l=%d k=%d", i, j, l, k);
				break;
			}
			else if (k == 10)
				printf("not a single point is within the right boundaries");
		}
	}
	return 0;
}
