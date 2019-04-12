#include <stdio.h>
#include <algorithm>

#pragma warning (disable : 4996)

using namespace std;

int n, f;
pair<int, int> p[3];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0, a; j < 3; j++)
			scanf("%d", &a), p[j].first += a, p[j].second += a * a;

	n = 0;

	if (p[0] < p[1]) n = 1;
	else if (p[0] == p[1]) f = 1;
	if (p[n] < p[2]) n = 2, f = 0;
	else if (p[n] == p[2]) f = 1;

	printf("%d %d\n", f ? 0 : n + 1, p[n].first);

	return 0;
}