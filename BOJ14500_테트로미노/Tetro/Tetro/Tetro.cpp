#include<stdio.h>
#pragma warning (disable : 4996)

int N, M, map[501][501];
int ma = 0;
int result = 0;

void max(int p, int q, int check, int sum, int(*m)[2]);
void max2(int p, int q);
int main()
{	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (ma < map[i][j]) ma = map[i][j];
			
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a = map[i][j];
			int visit[4][2] = { 0, };
			visit[0][0] = i; visit[0][1] = j;
			max(i, j, 1, a, visit);
			max2(i, j);
		}
	}

	printf("%d", result);
    return 0;
}

void max(int p, int q, int check, int sum, int (*m)[2])
{
	int v[4][2];
	for (int i = 0; i < 4; i++) { v[i][0] = m[i][0]; v[i][1] = m[i][1]; }
	if (check == 4) {
		if (result < sum) result = sum;
	}
	else if (check <= 3) {
		if (check == 3 && result >= (sum + ma));
		else {
			if (p + 1 >= 0 && p + 1 < N) {
				int ck = 0;
				for (int i = 0; i < check; i++) {
					if (p + 1 == v[i][0] && q == v[i][1]) ck = 1;
				}
				if (ck == 0) {
					v[check][0] = p + 1; v[check][1] = q;
					max(p + 1, q, check + 1, sum + map[p + 1][q], v);
				}
			}
			if (p - 1 >= 0 && p - 1 < N) {
				int ck = 0;
				for (int i = 0; i < check; i++) {
					if (p - 1 == v[i][0] && q == v[i][1]) ck = 1;
				}
				if (ck == 0) {
					v[check][0] = p - 1; v[check][1] = q;
					max(p - 1, q, check + 1, sum + map[p - 1][q], v);
				}
			}
			if (q + 1 >= 0 && q + 1 < M) {
				int ck = 0;
				for (int i = 0; i < check; i++) {
					if (p == v[i][0] && q + 1 == v[i][1]) ck = 1;
				}
				if (ck == 0) {
					v[check][0] = p; v[check][1] = q + 1;
					max(p, q + 1, check + 1, sum + map[p][q + 1], v);
				}
			}
			if (q - 1 >= 0 && q - 1 < M) {
				int ck = 0;
				for (int i = 0; i < check; i++) {
					if (p == v[i][0] && q - 1 == v[i][1]) ck = 1;
				}
				if (ck == 0) {
					v[check][0] = p; v[check][1] = q - 1;
					max(p, q - 1, check + 1, sum + map[p][q - 1], v);
				}
			}
		}
	}
}

void max2(int p, int q)
{
	if ((p + 1 >= 0 && p + 1 < N) && (p - 1 >= 0 && p - 1 < N) && (q + 1 >= 0 && q + 1 < M)) {
		if (result < (map[p][q] + map[p + 1][q] + map[p - 1][q] + map[p][q + 1])) result = (map[p][q] + map[p + 1][q] + map[p - 1][q] + map[p][q + 1]);
	}

	if ((p + 1 >= 0 && p + 1 < N) && (p - 1 >= 0 && p - 1 < N) && (q - 1 >= 0 && q - 1 < M)) {
		if (result < (map[p][q] + map[p + 1][q] + map[p - 1][q] + map[p][q - 1])) result = (map[p][q] + map[p + 1][q] + map[p - 1][q] + map[p][q - 1]);
	}

	if ((p + 1 >= 0 && p + 1 < N) && (q - 1 >= 0 && p - 1 < N) && (q + 1 >= 0 && q + 1 < M)) {
		if (result < (map[p][q] + map[p + 1][q] + map[p][q - 1] + map[p][q + 1])) result = (map[p][q] + map[p + 1][q] + map[p][q - 1] + map[p][q + 1]);
	}

	if ((p - 1 >= 0 && p - 1 < N) && (q - 1 >= 0 && p - 1 < N) && (q + 1 >= 0 && q + 1 < M)) {
		if (result < (map[p][q] + map[p - 1][q] + map[p][q - 1] + map[p][q + 1])) result = (map[p][q] + map[p - 1][q] + map[p][q - 1] + map[p][q + 1]);
	}
}
