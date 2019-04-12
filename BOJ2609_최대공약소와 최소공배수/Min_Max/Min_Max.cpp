#include<stdio.h>

#pragma warning (disable : 4996)

int min(int p, int q)
{
	int k, mi = 1;

	if (p > q) k = q;
	else if (p < q) k = p;
	else return p;

	for (int i = 2; i <= q; i++) 
		if (p%i == 0 && q%i == 0) mi = i;

	return mi;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int m = 0;
	m = min(a, b);
	printf("%d\n%d\n", m, (a*b/m));

	return 0;
}