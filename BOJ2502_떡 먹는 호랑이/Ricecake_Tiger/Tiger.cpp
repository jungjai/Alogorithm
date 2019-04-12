#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int pra = 1, prb = 0, a = 0, b = 1, tpa = 0, tpb = 0;

	int day, rice, checkA = 0, checkB = 0;

	scanf("%d %d", &day, &rice);

	for (int i = 3; i <= day; i++) {
		tpa = a; tpb = b;
		a += pra; b += prb;
		pra = tpa; prb = tpb;
	}

	checkA = rice / (a + b) + 1;
	
	for (int i = 1; i <= checkA; i++) {

		checkB = rice - i * a;

		if (checkB % b == 0) {
			printf("%d\n%d\n", i, checkB / b);
			i = rice;
		}
	}

	return 0;
}