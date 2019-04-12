#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int dice[6], su;

	for (int i = 0; i < 6; i++) dice[i] = 0;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &su);

		dice[su - 1]++;
	}

	for (int i = 0; i < 6; i++) {

		if (dice[i] == 3) {
			printf("%d\n", (i + 1) * 1000 + 10000);
			return 0;
		}
		else if (dice[i] == 2) {
			printf("%d\n", (i + 1) * 100 + 1000);
			return 0;
		}
		else if (dice[i] == 1) su = i + 1;
	}

	printf("%d\n", su * 100);

	return 0;
}