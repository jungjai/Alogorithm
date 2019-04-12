#include<stdio.h>
#pragma warning (disable : 4996)
int k, n, m;
int main()
{
	scanf("%d %d %d", &k, &n, &m);
	if (k*n <= m) printf("0\n");
	else printf("%d\n", k*n - m);
	return 0;
}