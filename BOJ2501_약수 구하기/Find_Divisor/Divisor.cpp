#include<stdio.h>

#pragma warning (disable : 4996)

int n, k;

int Divisor();

int main()
{
	int divi=0;

	scanf("%d %d", &n, &k);

	divi = Divisor();
	printf("%d\n",  divi);

	return 0;
}

int Divisor()
{
	int check = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			check++;
			if (check == k) return i;
		}
	}

	return 0;
}