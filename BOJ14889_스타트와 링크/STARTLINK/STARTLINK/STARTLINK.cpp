#include<stdio.h>

int N;
int S[21][21];
int total = 0;
int min;
int ca = 0;
void select(int, int, int *);

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
			total += S[i][j];
		}
	}
	min = total;

	int sel[21];
	for (int i = 0; i < N; i++) sel[i] = 0;
	select(0, 0, sel);
	printf("%d", min);
    return 0;
}

void select(int s, int p, int *se)
{
	if (p == N / 2) {

		//printf("\n");
		// (int i = 0; i < N; i++) printf("%d", se[i]);
		//ca++;
		int a = 0, b = 0, minus = 0;
		for (int i = 0; i < N; i++) {
			if (se[i] == 0) {
				for (int j = 0; j < N; j++) {
					if (se[j] == 0) a += S[i][j];
				}
			}
			else {
				for (int j = 0; j < N; j++) {
					if (se[j] == 1) b += S[i][j];
				}
			}
		}

		if (a >= b) minus = a - b;
		else minus = b - a;
		if (min > minus) min = minus;
	}

	else {
		for (int i = s; i < N; i++) {
			if (i >= N / 2 && p == 0);
			else {
				int copy[21];
				for (int j = 0; j < N; j++) copy[j] = se[j];
				if (p + (N - s) >= N / 2 && copy[i] == 0) {
					copy[i] = 1;
					select((i + 1), (p + 1), copy);
				}
			}
		}
	}
}