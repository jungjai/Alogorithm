#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su, sum = 1, ci[10], check = 0;

	int cip = 100000000;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &su);
		sum *= su;
	}
	for (int i = 0; i < 10; i++) ci[i] = 0;

	for (int i = 0; i < 9; i++) {
		if (check == 1 || ((sum / cip) != 0)) {
			check = 1;
			ci[(sum / cip)]++;

			sum = sum - ((sum / cip) *cip);
		}

		cip /= 10;
	}

	for (int i = 0; i < 10; i++) printf("%d\n", ci[i]);

	return 0;
}