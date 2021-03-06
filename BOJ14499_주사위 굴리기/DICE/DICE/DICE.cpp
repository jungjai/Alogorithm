#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int direction[4][6] = { { 2, 1, 5, 3, 0, 4 },{ 4, 1, 0, 3, 5, 2 },{ 3, 0, 2, 5, 4, 1 },{ 1, 5, 2, 0, 4, 3 } };
	int position[4][2] = { { 0, 1 },{ 0, -1 },{ -1, 0 },{ 1, 0 } };

	int map[20][20], N, M, x, y, K, ord;
	int dice[7];

	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);

	for (int i = 0; i < 6; i++) dice[i] = 0;

	map[x][y] = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d", &ord);
		ord--;
		int mock[6];
		for (int j = 0; j < 6; j++) mock[j] = dice[j];
		if (((x + position[ord][0]) >= 0 && (x + position[ord][0]) < N) && 
			((y + position[ord][1]) >= 0 && (y + position[ord][1]) < M)) {
			x += position[ord][0]; y += position[ord][1];

			for (int j = 0; j < 6; j++)
				dice[j] = mock[direction[ord][j]];

			if (map[x][y] == 0) map[x][y] = dice[0];
			else { dice[0] = map[x][y]; map[x][y] = 0; }

			printf("%d\n", dice[5]);
		}
	}

    return 0;
}