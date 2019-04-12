#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int su, check = 1;

	int all = 0;
	scanf("%d", &su);

	for (int i = 0; i < su; i++) {
		int score;
		
		scanf("%d", &score);

		if (score == 0) check = 1;
		else if (score == 1) {
			all += check;
			check++;
		}
	}
	printf("%d\n", all);
}