#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int X, jimin = 64, stick = 0, sum = 0;
	scanf("%d", &X);

	if (X == 64) printf("1\n");
	else {
		for (jimin = 32; jimin >= 1; jimin /= 2) {
			if (sum + jimin <= X) {
				sum += jimin; stick++;
				if (sum == X) {
					printf("%d\n", stick); return 0;
				}
			}			
		}
	}
    return 0;
}

	