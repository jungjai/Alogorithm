#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su, sum = 0, color[101][101];
	
	int tc, i, j, x1=100, y1=100, x2=0, y2=0;

	scanf("%d", &su);

	for (i = 0; i < 101; i++)
		for (j = 0; j < 101; j++) color[i][j] = 0;

	for (tc = 0; tc < su; tc++)
	{
		int p, q;
		scanf("%d %d", &p, &q);

		for (i = p; i < p + 10; i++) {
			for (j = q; j < q + 10; j++) {
				if (color[i][j] != 1) {
					color[i][j] = 1;
					sum += 1;
				}
			}
		}
	}

	printf("%d\n", sum);
}