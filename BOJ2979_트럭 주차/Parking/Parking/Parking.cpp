#include<stdio.h>

int main() {
	int a, b, c, sum = 0;
	int t[101] = { 0 };
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i < 3; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int j = x; j< y; j++) {
			t[j]++;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (t[i] == 1) {
			sum += a;
		}
		else if (t[i] == 2) {
			sum += b * 2;
		}
		else if (t[i] == 3) {
			sum += c * 3;
		}
	}
	printf("%d\n", sum);
}

