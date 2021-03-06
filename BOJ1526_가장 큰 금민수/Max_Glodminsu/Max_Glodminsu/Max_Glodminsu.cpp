#include <stdio.h>

int n, ans;

void go(int x)
{
	if (x>n) return;
	ans = ans<x ? x : ans;
	go(x * 10 + 4);
	go(x * 10 + 7);
}

int main()
{
	scanf("%d", &n);
	go(0);
	printf("%d", ans);
	return 0;
}