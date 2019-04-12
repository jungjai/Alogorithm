#include<stdio.h>

#pragma warning (disable : 4996)

int su, num;
int check[501][501];
int compare[250][2];

void CompareL(int n, int p);
void CompareM(int n, int p);

int main()
{
	freopen("input.txt", "r", stdin);

	int student = 0;

	scanf("%d %d", &su, &num);

	for (int i = 0; i < num; i++)
		scanf("%d %d", &compare[i][0], &compare[i][1]);

	for (int i = 1; i <= su; i++)
		for (int j = 1; j <= su; j++)
			check[i][j] = 0;

	for (int i = 0; i < num; i++) {
		check[compare[i][0]][compare[i][1]] = 1;
		CompareL(compare[i][0], compare[i][1]);
		check[compare[i][1]][compare[i][0]] = 1;
		CompareM(compare[i][1], compare[i][0]);
	}

	for (int i = 1; i <= su; i++) {
		int k = 0;
		for (int j = 1; j <= su; j++)
			k += check[i][j];
		if (k == su - 1) student++;
	}
	
	printf("%d\n", student);
}

void CompareL(int n, int p)
{
	for (int i = 0; i < num; i++) {
		if (p == compare[i][0]) {
			check[n][compare[i][1]] = 1;
			CompareL(n, compare[i][1]);
		}
	}
}

void CompareM(int n, int p)
{
	for (int i = 0; i < num; i++) {
		if (p == compare[i][1]) {
			check[n][compare[i][0]] = 1;
			CompareM(n, compare[i][0]);
		}
	}
}