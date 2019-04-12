#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su[101], n, sum = 0, bin = 0, binch = 0;
	int i;
	for (i = 1; i < 101; i++) su[i] = 0;

	for (i = 0; i < 10; i++) {
		scanf("%d", &n);

		su[n / 10]++;
		sum += n;
	}

	sum = sum / 10;
	n = 0;
	i = 1;
	while (i < 101 && n <=10)
	{
		if (su[i] > binch) {
			binch = su[i];
			bin = i * 10;
		}
		n += su[i];
		i++;
	}

	printf("%d\n%d\n", sum, bin);
}