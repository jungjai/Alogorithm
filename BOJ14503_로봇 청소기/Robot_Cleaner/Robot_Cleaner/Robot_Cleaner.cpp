#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int N, M, r, c, d, map[52][52], clean = 0, check = 1;
	int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	int b_dir[4][2] = { { 1, 0 },{ 0, -1 },{ -1, 0 },{ 0, 1 } };
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j <= M + 1; j++) map[i][j] = 1;

	scanf("%d %d %d", &r, &c, &d);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) scanf("%d", &map[i][j]);
	r++; c++;
	while (1) {
		if (map[r][c] == 0) {
			map[r][c] = 2;
			clean++;
		}

		if (d == 0) d = 4;
		if (map[dir[d - 1][0] + r][dir[d - 1][1] + c] == 0) {
			d--; check = 1;
			r += dir[d][0];
			c += dir[d][1];
		}
		else {
			if (check == 4) {
				if (map[b_dir[d - 1][0] + r][b_dir[d - 1][1] + c] != 1) {
					d--; check = 1;
					r += b_dir[d][0];
					c += b_dir[d][1];
				}
				else break;
			}
			else { d--; check++; }
		}
	}
	printf("%d\n", clean);
	return 0;
}