#include<stdio.h>

int N, M, K;

int A[52][52];
int K_info[7][3];
int visit[7];
int turn[7];
int min = 5001;

int score()
{
	int tmp[52][52];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) tmp[i][j] = A[i][j];

	for (int tc = 0; tc < K; tc++) {
		int cal = turn[tc];
		
		int dx[2], dy[2];
		dx[0] = K_info[cal][0] - K_info[cal][2];
		dx[1] = K_info[cal][0] + K_info[cal][2];
		dy[0] = K_info[cal][1] - K_info[cal][2];
		dy[1] = K_info[cal][1] + K_info[cal][2];
		
		while (dx[0] < dx[1]) {
			int check = tmp[dx[0]][dy[0]];
			for (int i = dx[0] + 1; i <= dx[1]; i++)
				tmp[i - 1][dy[0]] = tmp[i][dy[0]];
			for (int i = dy[0] + 1; i <= dy[1]; i++)
				tmp[dx[1]][i - 1] = tmp[dx[1]][i];
			for (int i = dx[1] - 1; i >= dx[0]; i--)
				tmp[i + 1][dy[1]] = tmp[i][dy[1]];
			for (int i = dy[1] - 1; i >= dy[0] + 1; i--)
				tmp[dx[0]][i + 1] = tmp[dx[0]][i];
			tmp[dx[0]][dy[0] + 1] = check;

			dx[0]++; dx[1]--; dy[0]++; dy[1]--;
		}
	}

	int result = 5001;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) sum += tmp[i][j];

		if (result > sum) result = sum;
	}
	return result;
}
void dfs(int total)
{
	if (total == K) {
		int tmp = score();
		if (min > tmp) min = tmp;
		return;
	}
	
	for (int i = 0; i < K; i++) {
		if (visit[i] == 0) {
			turn[total] = i; 
			visit[i] = 1;
			dfs(total + 1);
			visit[i] = 0;
		}
	}
}
int main()
{	
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
	for (int i = 0; i < K; i++) scanf("%d %d %d", &K_info[i][0], &K_info[i][1], &K_info[i][2]);

	dfs(0);
	printf("%d", min);
}