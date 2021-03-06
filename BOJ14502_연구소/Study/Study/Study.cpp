#include<stdio.h>
#pragma warning (disable : 4996)

int N, M, max = 0;;

void Safe(int(*vi)[10], int sa, int a, int b);
void Die(int(*d)[10], int p, int q);

int main()
{
	int virus[10][10];

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &virus[i][j]);
		}
	}

	Safe(virus, 0, 1, 1);

	printf("%d\n", max);
	return 0;
}

void Safe(int (*vi)[10], int sa, int a, int b)
{
	if (sa == 3) {
		int v[10][10];
		for (int p = 1; p <= N; p++)
			for (int q = 1; q <= M; q++) v[p][q] = vi[p][q];

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (v[i][j] == 2) {
					if (i + 1 <= N) {
						if (v[i + 1][j] == 0) {
							v[i + 1][j] = 3;
							Die(v, i + 1, j);
						}
					}
					if (i - 1 >= 1) {
						if (v[i - 1][j] == 0) {
							v[i - 1][j] = 3;
							Die(v, i - 1, j);
						}
					}
					if (j + 1 <= M) {
						if (v[i][j + 1] == 0) {
							v[i][j + 1] = 3;
							Die(v, i, j + 1);
						}
					}
					if (j - 1 >= 1) {
						if (v[i][j - 1] == 0) {
							v[i][j - 1] = 3;
							Die(v, i, j - 1);
						}
					}
				}
			}
		}

		int su = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (v[i][j] == 0) su++;

		if (su > max) {
			max = su;
		
		}
	}
	else if (sa < 3) {
		
		for (int i = a; i <= N; i++) {
			for (int j = b; j <= M; j++) {
				if (vi[i][j] == 0) {
					int v[10][10];
					for (int p = 1; p <= N; p++)
						for (int q = 1; q <= M; q++) v[p][q] = vi[p][q];
					v[i][j] = 1;
					Safe(v, sa + 1, i, j);
				}
			}
			b = 1;
		}
	}
}

void Die(int(*d)[10], int i, int j)
{
	if (i + 1 <= N) {
		if (d[i + 1][j] == 0) {
			d[i + 1][j] = 3;
			Die(d, i + 1, j);
		}
	}
	if (i - 1 >= 1) {
		if (d[i - 1][j] == 0) {
			d[i - 1][j] = 3;
			Die(d, i - 1, j);
		}
	}
	if (j + 1 <= M) {
		if (d[i][j + 1] == 0) {
			d[i][j + 1] = 3;
			Die(d, i, j + 1);
		}
	}
	if (j - 1 >= 1) {
		if (d[i][j - 1] == 0) {
			d[i][j - 1] = 3;
			Die(d, i, j - 1);
		}
	}
}