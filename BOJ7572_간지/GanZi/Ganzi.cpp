#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int gan = 9;
	char gi = 'F';

	int year;
	scanf("%d", &year);
	if (year > 2013) {
		while (year > 2013) {
			year--;
			gan++;
			if (gan > 9) gan = 0;
			gi = gi + 1;
			if (gi == 'L' + 1) gi = 'A';
		}
	}
	else if(year <2013) {
		while (year < 2013) {
			year++;
			gan--;
			if (gan < 0) gan = 9;
			gi = gi - 1;
			if (gi == 'A' - 1) gi = 'L';
		}
	}
	printf("%c%d\n", gi, gan);
	return 0;
}