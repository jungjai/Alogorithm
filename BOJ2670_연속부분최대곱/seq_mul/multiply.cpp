#include<stdio.h>

#pragma warning(disable : 4996)

void seq_mul(int n, double s[]);

int main()
{
	int num;
	int i;

	double su[10001];

	//freopen("input.txt", "r", stdin);

	scanf("%d", &num);

	if (num <= 10000 && num>0) {
		for (i = 0; i < num; i++)
			scanf("%lf", &su[i]);

		seq_mul(num, su);
	}

	return 0;
}

void seq_mul(int n, double s[])
{
	int i, j;
	double check = 0, mul = 0;

	mul = s[0];
	for (i = 0; i < n; i++)
	{
		check = 1;
		j = i;
		while (j < n) {
			check *= s[j];
			if (check > mul)
				mul = check;
			j++;
		}
		if (check > mul)
			mul = check;
	}
	printf("%.3lf\n", mul);
}