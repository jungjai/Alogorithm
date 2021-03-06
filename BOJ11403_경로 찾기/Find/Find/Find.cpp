#include<stdio.h>
#pragma warning (disable : 4996)

int N, check = 0;
int graph[101][101];
int visit[100];

void find(int p, int q);
int main()
{
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &graph[i][j]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check = 0;
			for (int z = 0; z < N; z++) visit[z] = 0;

			find(i, j);
			printf("%d ", check);
		}
		printf("\n");
	}
    return 0;
}

void find(int p, int q)
{
	if (visit[p] == 0) {
		if (graph[p][q] == 1) check = 1;
		else {
			visit[p] = 1;
			for (int i = 0; i < N; i++) {
				if (graph[p][i] == 1) find(i, q);
			}
		}
	}
}

