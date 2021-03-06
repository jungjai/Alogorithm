#include<stdio.h>

int N;
int exy[14][14];
int core[13][2], coresu = 0;
int resultcore = 0, length = 0;
void dfs(int p, int(*ex)[14], int total, int subcore);

int main()
{
	freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		scanf("%d", &N);

		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= N + 1; j++) exy[i][j] = -1;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &exy[i][j]);
				if (exy[i][j] == 1) {
					if (i == 1 || j == 1 || i == N || j == N);
					else {
						core[coresu][0] = i;
						core[coresu][1] = j;
						coresu++;
					}
				}
			}
		}
		dfs(0, exy, 0, 0);

		printf("#%d %d\n", T, length);

		//create
		for (int i = 0; i < coresu; i++) core[i][0] = core[i][1] = 0;
		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= N + 1; j++) exy[i][j] = 0;
		N = 0;
		coresu = 0;
		resultcore = 0, length = 0;
	}

	return 0;
}

void dfs(int p, int(*ex)[14], int total, int subcore)
{
	if (p == coresu) {
		if (subcore > resultcore) {
			resultcore = subcore;
			length = total;
		}
		if (subcore == resultcore && resultcore != 0) {
			if (length > total) length = total;
		}
	}
	else if(((coresu-p) + subcore) >= resultcore) {
		int e[14][14], toch = 0, check = 0, sub = 0;

		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= N + 1; j++) e[i][j] = ex[i][j];
		check = 0;
		sub = 0;
		for (int i = core[p][0] + 1; i <= N; i++) {
			if (e[i][core[p][1]] == 1) { check = 1, i = N; }
			sub++;
		}

		if (check == 0) {
			for (int i = core[p][0] + 1; i <= N; i++) {
				e[i][core[p][1]] = 1;
			}
			toch = 1; dfs(p + 1, e, total + sub, subcore + 1);
		}

		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= N + 1; j++) e[i][j] = ex[i][j];

		check = 0;
		sub = 0;
		for (int i = core[p][0] - 1; i >= 1; i--) {
			if (e[i][core[p][1]] == 1) { check = 1, i = 0; }
			sub++;
		}

		if (check == 0) {
			for (int i = core[p][0] - 1; i >= 1; i--) {
				e[i][core[p][1]] = 1;
			}
			toch = 1; dfs(p + 1, e, total + sub, subcore + 1);
		}

		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= N + 1; j++) e[i][j] = ex[i][j];

		check = 0;
		sub = 0;
		for (int i = core[p][1] + 1; i <= N; i++) {
			if (e[core[p][0]][i] == 1) { check = 1, i = N; }
			sub++;
		}

		if (check == 0) {
			for (int i = core[p][1] + 1; i <= N; i++) {
				e[core[p][0]][i] = 1;
			}
			toch = 1; dfs(p + 1, e, total + sub, subcore + 1);
		}
		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= N + 1; j++) e[i][j] = ex[i][j];

		check = 0;
		sub = 0;
		for (int i = core[p][1] - 1; i >= 1; i--) {
			if (e[core[p][0]][i] == 1) { check = 1, i = 0; }
			sub++;
		}

		if (check == 0) {
			for (int i = core[p][1] - 1; i >= 1; i--) {
				e[core[p][0]][i] = 1;
			}
			toch = 1; dfs(p + 1, e, total + sub, subcore + 1);
		}

		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= N + 1; j++) e[i][j] = ex[i][j];

		if (toch == 0) {
			dfs(p + 1, e, total, subcore);
		}
	}
}