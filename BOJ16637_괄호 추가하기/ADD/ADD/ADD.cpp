#include<stdio.h>

int num[11];
char op[10];

int check[10];
int N;
int max[2];

int cal(int p, int q, char three) {
	if (three == '+') return p + q;
	else if (three == '-') return p - q;
	else if (three == '*') return p * q;
	
	return -1;
}

int score() {
	int result[10] = {0, };

	for (int i = 0; i < N; i++) {
		if (check[i] == 1) {
			result[i] = cal(num[i], num[i + 1], op[i]);
		}
	}

	int total = 0;
	if (check[0]) total = result[0];
	else total = num[0];

	for (int i = 0; i < N; i++) {
		if (check[i] == 0) {
			if (check[i + 1] == 1 && (i + 1 < N)) total = cal(total, result[i + 1], op[i]);
			else total = cal(total, num[i + 1], op[i]);
		}
	}

	return total;
}

void dfs(int p) {
	for (int i = p; i < N; i++) {
		check[i] = 1;
		dfs(i + 2);
		check[i] = 0;
	}

	if (max[1] == 0) { max[0] = score(); max[1] = 1;}
	else {
		int tmp = score();
		if (tmp > max[0]) max[0] = tmp;
	}
	return;
}

int main()
{
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) scanf("%d", &num[i / 2]);
		else scanf("%c", &op[i / 2]);
	}

	if (N == 1) {
		printf("%d\n", num[0]); return 0;
	}
	if (N == 3) {
		printf("%d\n", cal(num[0], num[1], op[0])); return 0;
	}
	N = N / 2;
 	dfs(0);

	printf("%d\n", max[0]); return 0;
}