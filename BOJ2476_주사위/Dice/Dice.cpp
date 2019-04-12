#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int dice[3], person;

	int max = 0, check = 0;

	scanf("%d", &person);

	for (int i = 0; i < person; i++) {
		check = 0;
		scanf("%d %d %d", &dice[0], &dice[1], &dice[2]);

		if (dice[0] == dice[1] && dice[1] == dice[2]) check = dice[0] * 1000 + 10000;
		else if (dice[0] == dice[1] && dice[0] != dice[2]) check = dice[0] * 100 + 1000;
		else if (dice[0] == dice[2] && dice[0] != dice[1]) check = dice[0] * 100 + 1000;
		else if (dice[1] == dice[2] && dice[0] != dice[1]) check = dice[1] * 100 + 1000;
		else {
			for(int j=0;j<3;j++) {
				if (dice[j] > check) check = dice[j];
			}
			check *= 100;
		}

		if (max < check) max = check;
	}
	printf("%d\n", max);
}