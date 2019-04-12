#include<stdio.h>
#include<string.h>
#include<math.h>

#pragma warning(disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int sim = 0;

	int len, lenc;
	int num;
	int a1[26], a2[26];

	int i, j;
	int check[3];

	char str[101][11];

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%s", str[i]);
	}

	for (i = 0; i < 26; i++)
		a1[i] = 0;

	len = strlen(str[0]);

	for (i = 0; i < len; i++)
		a1[(str[0][i] - 'A')]++;

	for (i = 1; i < num; i++)
	{
		for (j = 0; j < 26; j++)
			a2[j] = 0;

		check[0] = 0; check[1] = 0; check[2] = 0;

		lenc = strlen(str[i]);
		for (j = 0; j < lenc; j++)
			a2[(str[i][j] - 'A')]++;

		for (j = 0; j < 26; j++) {
			if (a1[j] != a2[j])
			{
				check[0] = check[0] + abs(a1[j]-a2[j]);
				if (check[0] > 2) j = 26;
				else if (check[0] == 2) {
					if (check[1] == 1 && a1[j] < a2[j]) check[2] = 1;
					else if (check[1] == 2 && a1[j] > a2[j]) check[2] = 1;
				}
				else if (check[0] == 1) {
					if (a1[j] > a2[j]) check[1] = 1;
					else check[1] = 2;
				}
			}
		}

		if (check[0] <= 1) sim++;
		else if (check[0] == 2 && check[2] == 1) sim++;
	}

	printf("%d\n", sim);

	return 0;
}