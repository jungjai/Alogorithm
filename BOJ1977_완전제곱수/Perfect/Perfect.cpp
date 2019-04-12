#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int a, b, check = 0;
	scanf("%d %d", &a, &b);

	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i*i >= a && i*i <= b) {
			sum += i * i;
			if (check == 0) check = i * i;
		}
		else if(i*i > b) i = 101;
	}
	if (sum == 0) printf("-1\n");
	else printf("%d\n%d\n", sum, check);
	return 0;
}