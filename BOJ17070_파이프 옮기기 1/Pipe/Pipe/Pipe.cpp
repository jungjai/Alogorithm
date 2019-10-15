#include<stdio.h>

int N;
int space[17][17];
int result;

void dfs(int p, int q, int check)
{
	if (p == N - 1 && q == N - 1) {
		result++; return;
	}
	else {
		if (p < N && q < N) {
			if (space[p][q + 1] == 0 && check <= 1) dfs(p, q + 1, 0);
			if (space[p + 1][q] == 0 && check >= 1) dfs(p + 1, q, 2);
			if (space[p][q + 1] == 0 && space[p + 1][q] == 0 && space[p + 1][q + 1] == 0) dfs(p + 1, q + 1, 1);
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &space[i][j]);

	dfs(0, 1, 0);
	printf("%d", result);
}