#include<stdio.h>

#pragma warning(disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su;
	int student[100];
	int order[100];

	int i, j, temp;

	scanf("%d", &su);

	for (i = 0; i < su; i++) {
		scanf("%d ", &student[i]);
		order[i] = i + 1;
	}

	for (i = 1; i < su; i++) {
		for (j = 0; j < student[i]; j++) {
			temp = order[i - j];
			order[i - j] = order[i - j - 1];
			order[i - j - 1] = temp;
		}
	}

	for (i = 0; i < su; i++) printf("%d ", order[i]);
	printf("\n");

	return 0;
}