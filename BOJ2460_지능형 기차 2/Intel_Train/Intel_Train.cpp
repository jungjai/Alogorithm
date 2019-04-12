#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int max = 0, check = 0;

	for (int i = 0; i < 10; i++) {
		int in, out;

		scanf("%d %d", &out, &in);

		in -= out;

		check += in;

		if (max < check) max = check;
	}

	printf("%d\n", max);
	return 0;
}