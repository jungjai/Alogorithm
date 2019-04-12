#include<stdio.h>

#pragma warning(disable:4996) // scanf 쓰기 위해

void Yutnori(int y[]);

int main()
{
	int num;
	for (num = 0; num < 3; num++)
	{
		int yut[4];
		int i;
		for (i = 0; i < 4; i++)
			scanf("%d", &yut[i]);
		Yutnori(yut);
	}
	return 0;
}

void Yutnori(int y[])
{
	int i, check = 0;
	for (i = 0; i < 4; i++)
	{
		if (y[i] == 0) check++;
	}
	if (check == 1) printf("A\n");
	else if (check == 2) printf("B\n");
	else if (check == 3) printf("C\n");
	else if (check == 4) printf("D\n");
	else if (check == 0) printf("E\n");
}
