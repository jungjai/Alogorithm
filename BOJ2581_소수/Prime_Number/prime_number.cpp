#include<stdio.h>

#pragma warning(disable : 4996)

int prime(int su);

int main()
{
	freopen("input.txt", "r", stdin);

	int m = 0, n = 0, min=0, sum=0;

	scanf("%d", &m);
	scanf("%d", &n);

	for (int i = m; i <= n; i++) {
		if (prime(i) == 2) {
			if (sum == 0) min = i;
			sum += i;
		}
	}

	if (sum == 0) printf("-1\n");
	else printf("%d\n%d\n", sum, min);

	return 0;
}

int prime(int su)
{
	int i, k = 0;
	for (i = 1; i <= su; i++) {
		if (su%i == 0) k++;
		if(k>2) return 0;
	}
	return k;
}