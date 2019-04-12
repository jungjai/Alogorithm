#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int n, p, temp = 0;
	int k = 0;
	int check[1000], su = 0;

	scanf("%d %d", &n, &p);

	temp = n;
	while (k==0) {
		check[su] = temp;
		su++;
		temp = temp * n;
		temp %= p;
		for (int i = 0; i < su; i++) {
			if (temp == check[i]) {
				if (su - i == 1) printf("1\n");
				else  printf("%d\n", su - i);
				i = su; k = 1;
			}
		}
	}
}