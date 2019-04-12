#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su1, su2;

	int cip[4];
	int i, ten = 100;

	scanf("%d", &su1);
	scanf("%d", &su2);

	cip[3] = su2;

	for (i = 2; i >= 0; i--) {
		cip[i] = su2 / ten;
		su2 -= cip[i] * ten;
		ten = ten / 10;
	}

	for (i = 0; i < 4; i++)
		printf("%d\n", su1 * cip[i]);

	return 0;
}