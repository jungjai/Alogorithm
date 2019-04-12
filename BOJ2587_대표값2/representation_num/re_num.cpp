#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int su[5];

	int i, j, temp;
	
	int sum = 0;

	for (i = 0; i < 5; i++) {
		scanf("%d", &su[i]);
		sum += su[i];
	}

	for (i = 0; i < 4; i++) {
		for (j = i+1; j < 5; j++) {
			if (su[i] > su[j]) {
				temp = su[i];
				su[i] = su[j];
				su[j] = temp;
			}
		}
	}

	printf("%d\n%d\n", (sum / 5), su[2]);

	return 0;
}