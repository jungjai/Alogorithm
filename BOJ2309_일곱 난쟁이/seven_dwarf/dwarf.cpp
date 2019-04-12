#include<stdio.h>

#pragma warning(disable : 4996)

void dwarf_p(int p, int q, int dw[]);

int main()
{
	freopen("input.txt", "r", stdin);

	int su[9];

	int sum = 0;

	int i, j, temp;

	for (i = 0; i < 9; i++) {
		scanf("%d", &su[i]);
		sum += su[i];
	}

	for (i = 0; i < 8; i++)
		for (j = i + 1; j < 9; j++)
			if (su[i] > su[j])
			{
				temp = su[i];
				su[i] = su[j];
				su[j] = temp;
			}

	for (i = 0; i < 8; i++)
		for (j = i + 1; j < 9; j++)
			if ((sum - su[i] - su[j]) == 100) dwarf_p(i, j, su);
}

void dwarf_p(int p, int q, int dw[])
{
	int i;
	for (i = 0; i < 9; i++)
		if (i != p && i != q) printf("%d\n", dw[i]);
}