#include <stdio.h>

#pragma warning (disable : 4996)
#include <queue>
using namespace std;

int main() {
	int n, a[101][101] = { 0, }, s, e, m, d[101] = { 0, };
	scanf("%d%d%d%d", &n, &s, &e, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
	}
	queue<int> q;
	q.push(s);
	d[s] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		if (x == e) {
			printf("%d\n", d[x] - 1);
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			if (!a[x][i] || d[i]) continue;
			d[i] = d[x] + 1;
			q.push(i);
		}
	}
	printf("-1");
	return 0;
}