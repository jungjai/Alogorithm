#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int cu_h, cu_m, cook_time;

	int temp;

	int fi_h, fi_m;

	scanf("%d %d", &cu_h, &cu_m);
	scanf("%d", &cook_time);

	cu_m += cook_time;

	cu_h += (cu_m / 60);
	cu_m %= 60;
	cu_h %= 24;

	printf("%d %d\n", cu_h, cu_m);
}