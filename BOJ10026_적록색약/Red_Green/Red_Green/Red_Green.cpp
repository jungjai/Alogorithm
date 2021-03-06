#include<stdio.h>
#pragma warning(disable : 4996)

int N, map[102][102];
void Find(int p, int q, int color);

int main()
{
	char exm;
	int a = 0, b = 0, map2[102][102];

	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
			map2[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N+1; j++) {
			scanf("%c", &exm);
			if (exm == 'R') {
				map[i][j] = 1;
				map2[i][j] = 1;
			}
			else if (exm == 'G') {
				map[i][j] = 3;
				map2[i][j] = 1;
			}
			else if (exm == 'B') {
				map[i][j] = 2;
				map2[i][j] = 2;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] != 0) {	
				Find(i, j, map[i][j]);			
				a++;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = map2[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] != 0) {
				Find(i, j, map[i][j]);
				b++;
			}
		}
	}
	printf("%d %d", a, b);
    return 0;
}
void Find(int p, int q, int color)
{
	map[p][q] = 0;
	if (p<1 || p>N || q<1 || q>N) ;
	else {
		if (map[p][q + 1] == color) Find(p, q + 1, color);
		if (map[p][q - 1] == color) Find(p, q - 1, color);
		if (map[p + 1][q] == color) Find(p + 1, q, color);
		if (map[p - 1][q] == color) Find(p - 1, q, color);
	}
}
