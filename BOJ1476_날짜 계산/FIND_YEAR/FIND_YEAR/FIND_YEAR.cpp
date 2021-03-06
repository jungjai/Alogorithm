#include <stdio.h>

const int E = 15;
const int S = 28;
const int M = 19;

int e, s, m;

int find(int, int);

int main() {
	scanf("%d %d %d", &e, &s, &m);
	while (1) {
		if (find(s, E) == e && find(s, M) == m) break;
		s += S;
	}
	printf("%d", s);
	return 0;
}

int find(int n, int d) {
	return (n - 1) % d + 1;
}