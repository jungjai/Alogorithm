#include<stdio.h>

#pragma warning (disable:4996)

int bing[5][5], n;
int bingsu = 0;
int ga[5], se[5], da[2];

void check(int m);
int main()
{
	freopen("input.txt", "r", stdin);
	
	int i, j;

	for (i = 0; i < 5; i++) {
		ga[i] = 0; se[i] = 0;
		for (j = 0; j < 5; j++)
			scanf("%d", &bing[i][j]);
	}
	da[0] = 0; da[1] = 0;

	for (i = 1; i <= 25; i++) {
		scanf("%d", &n);
		check(n);

		if (bingsu >= 3) {
			printf("%d\n", i);
			i = 26;
		}
	}

	return 0;
}

void check(int m)
{
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (m == bing[i][j]) {
				
				ga[i]++, se[j]++;
				if (i == j) {
					da[0]++;
					if (da[0] == 5) bingsu++;
				}
				if((i+j) == 4) {
					da[1]++;
					if (da[1] == 5) bingsu++;
				}
				if (ga[i] == 5) bingsu++;
				if (se[j] == 5) bingsu++;

				i = 5; j = 5;
			}
		}
	}
}

