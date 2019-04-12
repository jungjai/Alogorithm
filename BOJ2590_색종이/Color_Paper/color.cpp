#include<stdio.h>

#pragma warning (disable :4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int paper[6];

	int pan = 0;

	int i, check = 0, namu = 0;

	for (i = 0; i < 6; i++)
		scanf("%d", &paper[i]);

	pan += paper[5];
	paper[5] = 0;

	if (paper[4] > 0) {
		pan += paper[4];
		
		if (paper[0] > 0) paper[0] = paper[0] - (paper[4] * 11);
		paper[4] = 0;
	}

	if (paper[3] > 0) {
		pan += paper[3];

		if (paper[1] > 0) {
			if (paper[1] >= paper[3] * 5) paper[1] = paper[1] - (paper[3] * 5);
			else {
				check = (paper[3] * 5) - paper[1];
				if (paper[0] > 0)
					paper[0] = paper[0] - (check * 4);

				paper[1] = 0;
			}		
			check = 0;
		}
		else if (paper[0] > 0) paper[0] = paper[0] - (paper[3] * 20);
		paper[3] = 0;
	}

	if (paper[2] > 0) {
		namu = paper[2] % 4;
		if(namu == 0) pan += (paper[2] / 4);
		else {
			pan += (paper[2] / 4) + 1;

			if (paper[1] > 0) {
				if (namu == 3) {
					paper[1] = paper[1] - 1;
					if (paper[0] > 0) paper[0] = paper[0] - 5;
				}
				else if (namu == 2) {
					if (paper[1] >= 3) {
						paper[1] = paper[1] - 3;
						if (paper[0] > 0) paper[0] = paper[0] - 6;
					}
					else {
						check = 3- paper[1];
						if (paper[0] > 0)
							paper[0] = paper[0] - (check * 4 + 6);

						paper[1] = 0;
					}
					check = 0;
				}
				else if (namu == 1) {
					if (paper[1] >= 5) {
						paper[1] = paper[1] -  5;
						if (paper[0] > 0) paper[0] = paper[0] - 7;
					}
					else {
						check = 5 - paper[1];
						if (paper[0] > 0)
							paper[0] = paper[0] - (check * 4 + 7);

						paper[1] = 0;
					}
					check = 0;
				}
			}
			else if (paper[0] > 0) paper[0] = paper[0] - ((4 - namu) * 9);
		}

		paper[2] = 0;
		namu = 0;
	}

	if (paper[1] > 0) {
		namu = paper[1] % 9;
		if (namu == 0) pan += (paper[1] / 9);
		else {
			pan += (paper[1] / 9) + 1;

			if (paper[0] > 0) paper[0] = paper[0] - ((9 - namu) * 4);
		}

		paper[1] = 0;
		namu = 0;
	}

	if (paper[0] > 0) {
		pan += (paper[0] / 36);
		if (paper[0] % 36 != 0) pan++;

		paper[0] = 0;
	}

	printf("%d\n", pan);

	return 0;
}