#include<stdio.h>

int N, total_su;
int su[11];

int info[11];
int space[11][11];

int visit[11];
int min, min_check;

void check_dfs(int p, int *check_di) {
	for (int i = 0; i < info[p]; i++) {
		if (check_di[space[p][i] - 1] != 1 && visit[space[p][i] - 1] == 0) {
			check_di[space[p][i] - 1] = 1;
			check_dfs(space[p][i] - 1, check_di);
		}
	}
	return;
}
int score()
{
	int check_di[11] = { 0, };

	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			check_di[i] = 1;
			check_dfs(i, check_di);
			i = N;
		}
	}

	int A_su = 0, B_su = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 1) A_su += su[i];
		else if (check_di[i] == 0) return -1;
	}
	B_su = total_su - A_su;
	if (A_su >= B_su) return A_su - B_su;
	else return B_su - A_su;
}
void dfs(int p, int total)
{
	if (total == N) return;

	int tmp = score();
	if (tmp != -1) {
		if (min_check == 0) {
			min_check = 1;
			min = tmp;
		}
		else {
			if (min > tmp) min = tmp;
		}
	}

	for (int i = 0; i < info[p]; i++) {
		if (visit[space[p][i] - 1] != 1) {
			visit[space[p][i] - 1] = 1;
			dfs(space[p][i] - 1, total + 1);
			visit[space[p][i] - 1] = 0;
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &su[i]);
		total_su += su[i];
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &info[i]);
		for (int j = 0; j < info[i]; j++) scanf("%d", &space[i][j]);
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		dfs(i, 1);
		visit[i] = 0;

	}
	if (min_check == 0) printf("-1\n");
	else printf("%d\n", min);
}