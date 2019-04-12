#include<stdio.h>

#pragma warning (disable : 4996)
	
int main()
{
	int w, h, p, q, time;
	int x = 1, y = 1;
	scanf("%d %d", &w, &h);
	scanf("%d %d", &p, &q);
	scanf("%d", &time);
	while (time > 0)
	{
		time--;
		if (p == w || p == 0) x *= -1;
		if (q == h || q == 0) y *= -1;
		p += x;
		q += y;
	}
	printf("%d %d\n", p, q);
	return 0;
}