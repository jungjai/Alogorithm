#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int su, sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &su);
		sum += su*su;
	}
	printf("%d\n", sum % 10);

	return 0;
}