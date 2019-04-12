#include<stdio.h>

#pragma warning (disable : 4996)

int su = 0, stair[302];
int score = 0;

void Climbstair(int n, int check, int seq);

int main()
{
	freopen("input.txt", "r", stdin);

	int i;

	scanf("%d", &su);

	for (i = 0; i <su; i++)
		scanf("%d", &stair[i]);

	Climbstair(0, 0, 1);
	Climbstair(1, 0, 1);

	printf("%d\n", score);
}

void Climbstair(int n, int check, int seq)
{
	if(n == su-1) {
		check += stair[n];
		if (score < check) 
			score = check;
	}
	else if (n < su) {
		if (seq == 1) Climbstair(n + 1, check+stair[n], 2);

		Climbstair(n + 2, check+stair[n], 1);
	}
}