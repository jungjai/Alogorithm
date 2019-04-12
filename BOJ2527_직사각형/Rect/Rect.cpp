#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int x1, y1, x2, y2, tx1, ty1, tx2, ty2;
	for (int tc = 0; tc < 4; tc++) {
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &tx1, &ty1, &tx2, &ty2);

		if ((x2 == tx1 && y2 == ty1) || (x1 == tx2 && y2 == ty1) || (x2 == tx1 && y1 == ty2) || (x1 == tx2 && y1 == ty2)) printf("c\n");
		else if ((x2 == tx1 && y2 != ty1) || (x1 == tx2 && y2 != ty1) || (x2 != tx1 && y1 == ty2) || (x1 != tx2 && y1 == ty2)) printf("b\n");
		else if (x2 < tx1 || tx2 < x1 || y2 < ty1 || ty2 < y1) printf("d\n");
		else printf("a\n");
	}

	return 0;
}