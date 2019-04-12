#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int day, check = 0;
	scanf("%d", &day);
	for (int i = 0; i < 5; i++) {
		int n;
		scanf("%d", &n);
		if (n == day) check++;
	}

	printf("%d\n", check);
}