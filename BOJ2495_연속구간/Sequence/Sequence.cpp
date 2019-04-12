#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	char su[9];
	int check[3];
	for (int i = 0; i < 3; i++) {
		scanf("%s", su);
		check[i] = 0;

		int ch = 1;

		for (int j = 1; j < 8; j++) {
			if (su[j] == su[j - 1]) ch++;
			else {
				if (check[i] < ch) check[i] = ch;
				ch = 1;
			}
		}

		if (check[i] < ch) check[i] = ch;
	}

	for (int i = 0; i < 3; i++) printf("%d\n", check[i]);

	return 0;


}