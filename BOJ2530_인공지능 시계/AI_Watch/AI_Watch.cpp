#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int cu_h, cu_m, cu_s, cook_time;

	scanf("%d %d %d", &cu_h, &cu_m, &cu_s);
	scanf("%d", &cook_time);

	cu_s += cook_time;
	cu_m += (cu_s / 60);
	cu_h += (cu_m / 60);
	cu_s %= 60;
	cu_m %= 60;
	cu_h %= 24;

	printf("%d %d %d\n", cu_h, cu_m, cu_s);
}