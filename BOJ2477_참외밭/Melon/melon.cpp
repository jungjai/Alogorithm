#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int melon = 0;
	int dir[6];
	int len[6];
	int k = 0;
	int area = 1, ep = 1;
	scanf("%d", &melon);

	for (int i = 0; i < 6; i++) {
		scanf("%d %d", &dir[i], &len[i]);
	}
	for (int i = 0; i < 6; i++) {
		if (area < len[i] * len[(i + 1) % 6]) {
			area = len[i] * len[(i + 1) % 6];
			k = i;
		}
	}
	ep = len[(k + 3) % 6] * len[(k + 4) % 6];
	area -= ep;
	printf("%d\n", melon*area);

	return 0;
}