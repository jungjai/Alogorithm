#include<stdio.h>

#pragma warning(disable : 4996)

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int Kr = 0, Ys = 0;
		for (int j = 0; j < 9; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			Ys += a;
			Kr += b;
		}
		if (Kr > Ys) printf("Korea\n");
		else if (Kr < Ys) printf("Yonsei\n");
		else printf("Draw\n");
	}

	return 0;
}