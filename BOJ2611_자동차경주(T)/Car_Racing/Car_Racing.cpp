#include<stdio.h>

#pragma warning (disable : 4996)

int n, m, route[10000][3];
int max = 0, R[1001];

void find(int p, int score, int check, int *ro);

int main()
{
	//freopen("input.txt", "r", stdin);

	int ro[1001];

	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &route[i][0], &route[i][1], &route[i][2]);
	ro[0] = 1;
	find(1, 0, 1, ro);

	printf("%d\n", max);
	for (int i = 0; i < n; i++) printf("%d ", R[i]);
	return 0;
}

void find(int p, int score, int check, int *ro) {
	int r[1001];

	for (int i = 0; i < check; i++)
		r[i] = ro[i];
	for (int i = 0; i < m; i++) {
		if (route[i][0] == p) {
			if (route[i][1] == 1) {
				if (max < (score + route[i][2])) {
					max = score + route[i][2];
					for (int i = 0; i < check; i++) R[i] = r[i];
					R[check] = 1;
				}
			}
			else {
				r[check] = route[i][1];
				check++;
				find(route[i][1], score+route[i][2], check, r);
			}
		}
	}
}