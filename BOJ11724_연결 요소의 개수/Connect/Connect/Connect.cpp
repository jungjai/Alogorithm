#include<stdio.h>
#pragma warning (disable : 4996)

int N, M;
int line[50000][2];
int visit[1001], ch = 0;

void find(int p, int q);
int main()
{
	int total = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) scanf("%d %d", &line[i][0], &line[i][1]);
	for (int i = 1; i <= N; i++) {
		int check = 0;
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				ch = 0;
				for (int z = 0; z < N; z++) visit[z] = 0;
				find(i, j);
				if (ch == 0) {
					check = 1; j = N + 1;
				}
			}
		}
		if (check == 0) total++;
	}
	printf("%d\n", total);
    return 0;
}

void find(int p, int q)
{
	if (visit[p] == 0) {
		for (int i = 0; i < M; i++) {
			if ((line[i][0] == p && line[i][1] == q) || (line[i][0] == q && line[i][1] == p))
			{
				ch = 1; printf("%d %d\n", p, q);
			}
		}
		if (ch == 0) {
			visit[p] = 1;
			for (int i = 0; i < M; i++) {
				if (line[i][0] == p) find(line[i][1], q);
				else if (line[i][1] == p) find(line[i][0], q);
			}
		}
		
	}
	
}

