#include<stdio.h>
#include<string.h>
#pragma warning (disable : 4996)

int main()
{
	char X[51], Y[51];
	int lenx, leny, min;
	scanf("%s %s", X, Y);
	lenx = strlen(X);
	leny = strlen(Y);
	
	min = lenx;
	for (int i = 0; i <= leny - lenx; i++) {
		int check = 0;
		for (int j = 0; j < lenx; j++) {
			if (X[j] != Y[i + j]) check++;
		}
		if (check < min) min = check;
	}
	printf("%d\n", min);
    return 0;
}