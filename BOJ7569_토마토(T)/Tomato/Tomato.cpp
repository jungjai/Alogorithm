#include<stdio.h>

#pragma warning (disable: 4996)

int m, n, h;
int tomato[100][100][100];

int Q[1000001][3], check = 0;

void Tomato_find(int p);
void front();

int main()
{
	freopen("input.txt", "r", stdin);

	int jump = 0, day = 0;

	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &tomato[i][j][k]);

				if (tomato[i][j][k] == 1) {
					Q[check][0] = i; Q[check][1] = j; Q[check][2] = k;
					check++;
				}
				if (tomato[i][j][k] == 0) jump = 1;
			}
		}
	}

	if (jump == 0) {
		printf("0\n");
		return 0;
	}

	while (check > 0) {
		day++;
		int check_check;
		check_check = check;
		for (int i = 0; i < check_check; i++) Tomato_find(0);
	}

	day--;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (tomato[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}
			}		
		}	
	}

	printf("%d\n", day);
}

void Tomato_find(int p)
{
	int tm_h, tm_m, tm_n;
	tm_h = Q[p][0]; tm_m = Q[p][1]; tm_n = Q[p][2];

	front(); check--;

	if (tm_h - 1 >= 0 && tomato[tm_h - 1][tm_m][tm_n] == 0) {
		tomato[tm_h - 1][tm_m][tm_n] = 1;
		Q[check][0] = tm_h - 1; Q[check][1] = tm_m; Q[check][2] = tm_n;
		check++;
	}
	if (tm_h + 1 < h && tomato[tm_h + 1][tm_m][tm_n] == 0) {
		tomato[tm_h + 1][tm_m][tm_n] = 1;
		Q[check][0] = tm_h + 1; Q[check][1] = tm_m; Q[check][2] = tm_n;
		check++;
	}
	if (tm_m - 1 >= 0 && tomato[tm_h][tm_m - 1][tm_n] == 0) {
		tomato[tm_h][tm_m - 1][tm_n] = 1;
		Q[check][0] = tm_h; Q[check][1] = tm_m - 1; Q[check][2] = tm_n;
		check++;
	}
	if (tm_m + 1< m && tomato[tm_h][tm_m + 1][tm_n] == 0) {
		tomato[tm_h][tm_m + 1][tm_n] = 1;
		Q[check][0] = tm_h; Q[check][1] = tm_m + 1; Q[check][2] = tm_n;
		check++;
	}
	if (tm_n - 1>= 0 && tomato[tm_h][tm_m][tm_n - 1] == 0) {
		tomato[tm_h][tm_m][tm_n - 1] = 1;
		Q[check][0] = tm_h; Q[check][1] = tm_m; Q[check][2] = tm_n - 1;
		check++;
	}
	if (tm_n + 1< n && tomato[tm_h][tm_m][tm_n + 1] == 0) {
		tomato[tm_h][tm_m][tm_n + 1] = 1;
		Q[check][0] = tm_h; Q[check][1] = tm_m; Q[check][2] = tm_n + 1;
		check++;
	}
}
void front()
{
	for (int i = 1; i < check; i++)
		for (int j = 0; j < 3; j++)
			Q[i - 1][j] = Q[i][j];
}