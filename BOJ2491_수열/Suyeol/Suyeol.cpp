#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	freopen("input.txt", "r", stdin);

	int n, length = 0;
	int su[100001], sum = 2, check = 0;

	scanf("%d", &n);

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	for (int i = 0; i < n; i++) scanf("%d", &su[i]);

	if (su[0] < su[1]) check = 1;
	else if(su[0] > su[1]) check = 2;

	for (int i = 2; i < n; i++) {
		if (su[i] == su[i - 1]) sum++;

		else if (su[i] > su[i - 1]) {
			if (check == 0 || check == 1) {
				check = 1;
				sum++;
			}
			else {
				check = 1;
				if (length < sum) length = sum;
				int j = i-1;
				sum = 2;
				while (su[j] == su[j - 1]) {
					sum++;
					j--;
				}
			}
		}

		else if (su[i] < su[i - 1]) {
			if (check == 0 || check == 2) {
				check = 2;
				sum++;
			}
			else {
				check = 2;
				if (length < sum) length = sum;
				int j = i-1;
				sum = 2;
				while (su[j] == su[j - 1]) {
					sum++;
					j--;
				}
			}
		}
	}

	if (length < sum) length = sum;

	printf("%d\n", length);

	return 0;
}