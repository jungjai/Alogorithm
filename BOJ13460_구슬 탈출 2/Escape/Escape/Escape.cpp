#include<stdio.h>
#include<math.h>

int map[11][11]; // # : -1, . : 0, O : 7, R : 1, B : 2
int rx, ry, bx, by;

int rb[1000000][4], visit[11][11][11][11];
int count = 0;
int N, M;
int check = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void escape();
int main()
{
	int time = 10; char c;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &c);
			if (c == '#') map[i][j] = -1;
			else if (c == '.') map[i][j] = 0;
			else if (c == 'O') map[i][j] = 7;
			else if (c == 'R') {
				rx = i; ry = j; map[i][j] = 0;
			}
			else if (c == 'B') {
				bx = i; by = j; map[i][j] = 2;
			}
		}scanf("%c", &c);
	}
	visit[rx][ry][bx][by] = 1;
	rb[0][0] = rx; rb[0][1] = ry; rb[0][2] = bx; rb[0][3] = by;
	count = 1;
	while (time > 0) {
		time--;
		escape();
		if (check == 1) {
			printf("%d", 10 - time);  time = 0;
		}
	}
    return 0;
}

void escape()
{
	int copy[1000000][4]; int cc = 0;
	int check1, check2;
	for (int T = 0; T < count; T++) {
		for (int i = 0; i < 4; i++) {
			int x1, y1, x2, y2;
			x1 = rb[T][0]; y1 = rb[T][1]; x2 = rb[T][2]; y2 = rb[T][3];

			if (map[x1][y1] == 7) {
				if (x1 == x2 && y1 == y2);
				else {
					check = 1; T = count;
				}
			}
			while (1) {
				if (map[x1 + dx[i]][y1 + dy[i]] != 7 && map[x1 + dx[i]][y1 + dy[i]] != -1) {
					x1 += dx[i]; y1 += dy[i];
				}
				else break;
			}
			while (1) {
				if (map[x2 + dx[i]][y2 + dy[i]] != 7 && map[x2 + dx[i]][y2 + dy[i]] != -1) {
					x2 += dx[i]; y2 += dy[i];
				}
				else break;
			}
			if (x1 == x2 && y1 == y2) {
				if (map[x1][y1] == 7);
				else {
					if ((abs(x1 - rb[T][0]) + abs(y1 - rb[T][1])) < (abs(x2 - rb[T][2]) + abs(y2 - rb[T][3]))) {
						x1 -= dx[i];
						y1 -= dy[i];
					}
					else {
						x2 -= dx[i];
						y2 -= dy[i];
					}
				}
			}

			if (visit[x1][y1][x2][y2] != 1) {
				copy[cc][0] = x1; copy[cc][1] = y1; copy[cc][2] = x2; copy[cc][3] = y2;
				visit[x1][y1][x2][y2] == 1; cc++;
			}
		}
	}
	if (check != 1) {
		for (int i = 0; i < cc; i++)
			for (int j = 0; j < 4; j++) rb[i][j] = copy[i][j];
	}
}
			
		
