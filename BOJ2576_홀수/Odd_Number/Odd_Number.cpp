#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su, sum = 0, min = 100;

	for (int i = 0; i < 7; i++) {

		scanf("%d", &su);

		if (((su % 2) == 1) && su<100) {
			sum += su;
			if (min > su) min = su;
		}
	}
	if (min == 100) printf("-1\n");
	else printf("%d\n%d\n", sum, min);

	return 0;
}