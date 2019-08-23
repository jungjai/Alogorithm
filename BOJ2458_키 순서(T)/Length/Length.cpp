#include<stdio.h>

int map[501][501];
int ans;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int x, y;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (i == j || j == k || i == k) continue;
				if (map[i][k] && map[k][j])
					map[i][j] = 1;
			}
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;

			if (map[i][j] || map[j][i])
				cnt++;
		}
		if (cnt >= N - 1)
			ans++;
	}
	printf("%d", ans);
	return 0;
}
