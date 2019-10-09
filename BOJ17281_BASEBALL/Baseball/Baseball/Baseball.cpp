#include<stdio.h>

int N;
int player[51][10];
int max = 0;
int tason[10];
int visit[10];

int score() {
	int result = 0;
	int base[3] = { 0,0,0 };
	int check = 0;

	for (int i = 0; i < N; i++) {
		int out = 3;
		int j = check;
		while (out > 0) {
			for (; j < 9; j++) {
				int situ = player[i][tason[j]];
				if (situ == 1) {
					if (base[2] == 1) result++;
					base[2] = base[1]; base[1] = base[0]; base[0] = 1;
				}
				else if (situ == 2) {
					if (base[2] == 1) result++;
					if (base[1] == 1) result++;
					base[2] = base[0]; base[1] = 1; base[0] = 0;
				}
				else if (situ == 3) {
					if (base[2] == 1) result++;
					if (base[1] == 1) result++;
					if (base[0] == 1) result++;
					base[2] = 1; base[1] = 0; base[0] = 0;
				}
				else if (situ == 4) {
					result++;
					result = result + base[0] + base[1] + base[2];
					base[2] = 0; base[1] = 0; base[0] = 0;
				}
				else if (situ == 0) {
					out--;
					if (out == 0) { check = j + 1; j = 9; }
				}
			}
			j = 0;
		}
		base[2] = 0; base[1] = 0; base[0] = 0;
	}
	return result;
}
void dfs(int total) {
	if (total == 4) {
		dfs(total + 1);
		return;
	}

	if (total == 10) {
		int result = score();

		if (max < result) {
			max = result;
		}
		return;
	}
	for (int i = 1; i < 9; i++) {
		if (visit[i] == 0) {
			tason[total - 1] = i;
			visit[i] = 1;
			dfs(total + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &player[i][j]);
		}
	}
	tason[3] = 0; visit[0] = 1;
	dfs(1);
	printf("%d\n", max);
}