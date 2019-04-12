#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int N, kim, im, round = 0, check = 0;
	scanf("%d %d %d", &N, &kim, &im);

	if (kim > im) {
		int tmp;
		tmp = kim;
		kim = im;
		im = tmp;
	}

	while (N >= 2) {
		round++;
		if ((kim % 2 != 0) && ((kim + 1) == im)) {
			check = 1; break;
		}
		else {
			if (kim % 2 == 0) kim = kim / 2;
			else kim = kim / 2 + 1;

			if (im % 2 == 0) im = im / 2;
			else im = im / 2 + 1;

			if (N % 2 == 0) N = N / 2;
			else N = N / 2 + 1;
		}
	}

	if (check == 1) printf("%d\n", round);
	else printf("-1\n");
	return 0;
}