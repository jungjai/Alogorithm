#include<stdio.h>
#pragma warning (disable : 4996)

int N, map[21][21];
int check = 0;
int size = 2;
int sx, sy;
int bf[400][2], bc;
int total = 0;
int eat = 0;
int visit[21][21];

void find(int, int);
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				sx = i, sy = j;
				map[i][j] = 0;
			}
		}
	}
	while (1) {
		check = 0; bf[0][0] = sx; bf[0][1] = sy;
		bc = 1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) visit[i][j] = 0;
		visit[sx][sy] = 1;

		find(1, bc);
		if (check == 0) {
			printf("%d\n", total);
			return 0;
		}
	}
	return 0;
}

void find(int count, int su)
{
	int copy[400][2], cc = 0;
	int rx = N, ry = N;
	for (int i = 0; i < su; i++) {
		int x = bf[i][0], y = bf[i][1];
		if (x + 1 >= 0 && x + 1 < N && visit[x+1][y] == 0) {
			visit[x + 1][y] = 1;
			if (size < map[x + 1][y]);
			else if (size == map[x + 1][y] || map[x + 1][y] == 0) {
				int chec = 0;
				for (int j = 0; j < cc; j++) {
					if (copy[j][0] == (x + 1) && copy[j][1] == y) {
						chec = 1; j = cc;
					}
				}
				if (chec == 0) { copy[cc][0] = x + 1; copy[cc][1] = y; cc++; }
			}
			else {
				if (rx > x + 1 || (rx == x+1 && ry > y)) {
					rx = x + 1; ry = y;
					check = 1;
				}
			}
		}

		if (x - 1 >= 0 && x - 1 < N && visit[x - 1][y] == 0) {
			visit[x - 1][y] = 1;
			if (size < map[x - 1][y]);
			else if (size == map[x - 1][y] || map[x - 1][y] == 0) {
				int chec = 0;
				for (int j = 0; j < cc; j++) {
					if (copy[j][0] == (x - 1) && copy[j][1] == y) {
						chec = 1; j = cc;
					}
				}
				if (chec == 0) { copy[cc][0] = x - 1; copy[cc][1] = y; cc++; }
			}
			else {
				if (rx > x - 1 || (rx == x - 1 && ry > y)) {
					rx = x - 1; ry = y;
					check = 1;
				}
			}
		}

		if (y + 1 >= 0 && y + 1 < N && visit[x][y + 1] == 0) {
			visit[x][y + 1] = 1;
			if (size < map[x][y + 1]);
			else if (size == map[x][y + 1] || map[x][y + 1] == 0) {
				int chec = 0;
				for (int j = 0; j < cc; j++) {
					if (copy[j][0] == x && copy[j][1] == y + 1) {
						chec = 1; j = cc;
					}
				}
				if (chec == 0) { copy[cc][0] = x; copy[cc][1] = y + 1; cc++; }
			}
			else {
				if (rx > x || (rx == x && ry > (y + 1))) {
					rx = x; ry = y + 1;
					check = 1;
				}
			}
		}

		if (y - 1 >= 0 && y - 1 < N && visit[x][y - 1] == 0) {
			visit[x][y - 1] = 1;
			if (size < map[x][y - 1]);
			else if (size == map[x][y - 1] || map[x][y - 1] == 0) {
				int chec = 0;
				for (int j = 0; j < cc; j++) {
					if (copy[j][0] == x && copy[j][1] == y - 1) {
						chec = 1; j = cc;
					}
				}
				if (chec == 0) { copy[cc][0] = x; copy[cc][1] = y - 1; cc++; }
			}
			else {
				if (rx > x || (rx == x && ry > (y - 1))) {
					rx = x; ry = y - 1;
					check = 1;
				}
			}
		}
	}

	if (check == 1) {
		map[rx][ry] = 0; sx = rx; sy = ry;
		total += count;
		eat++;
		if (eat == size) {
			size++; eat = 0;
		}
	}
	else if (check == 0 && cc != 0) {
		for (int i = 0; i < cc; i++) {
			bf[i][0] = copy[i][0]; bf[i][1] = copy[i][1];
		}
		bc = cc;
		find(count + 1, bc);
	}
}