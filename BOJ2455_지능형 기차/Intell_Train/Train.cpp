#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int max = 0, person = 0;
	int in, out;

	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &out, &in);

		in = in - out;

		person += in;

		if (max < person) max = person;
	}

	printf("%d\n", max);

	return 0;
}