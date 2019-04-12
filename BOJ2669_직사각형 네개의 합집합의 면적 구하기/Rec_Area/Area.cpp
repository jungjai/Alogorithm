#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int x1, x2, y1, y2;
	int area[101][101];
	int sum = 0;

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			area[i][j] = 0;

	for (int tc = 0; tc < 4; tc++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				area[i][j] = 1;
	}
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if(area[i][j] == 1) sum++;

	printf("%d\n", sum);
	return 0;
}