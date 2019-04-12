#include<stdio.h>

#pragma warning(disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su, max=0, num=0;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &su);
		if (max < su) {
			max = su;
			num = i;
		}
	}

	printf("%d\n%d\n", max, num);
	return 0;
}