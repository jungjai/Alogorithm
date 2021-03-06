#include<stdio.h>

int main()
{
	int N, map[101][101];
	int cur[4][2] = { {1,0}, {0, -1}, {-1, 0}, {0, 1} };
	scanf("%d", &N);
	
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++) map[i][j] = 0;

	for (int T = 0; T < N; T++) {
		int x, y, d, g, dc[1025];
		int two = 2;

		scanf("%d %d %d %d", &x, &y, &d, &g);
		
		dc[1] = d;
		for (int i = 1; i <= g; i++) {
			int mi = 1;
			for (int j = (two / 2) + 1; j <= two; j++) {
				dc[j] = (dc[j - mi] + 1) % 4;
				mi += 2;
			}
			two *= 2;
		}
		
		map[y][x] = 1;
		for (int i = 1; i <= (two / 2); i++) {
			x += cur[dc[i]][0];
			y += cur[dc[i]][1];

			map[y][x] = 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) result++;
		}
	}
	printf("%d\n", result);

    return 0;
}