#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int L, A, B, C, D;
	int day1, day2;

	scanf("%d", &L);
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);

	if (A%C == 0) day1 = A / C;
	else day1 = (A / C) + 1;
	if (B%D == 0) day2 = B / D;
	else day2 = (B / D) + 1;
	
	if (day1 > day2) L = L - day1;
	else L = L - day2;
	printf("%d", L);
    return 0;
}