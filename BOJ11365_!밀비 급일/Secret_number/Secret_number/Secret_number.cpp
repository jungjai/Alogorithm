#include<stdio.h>
#include<string.h>

int main()
{
	char end[4];
	strcpy(end, "END");
	while (1) {
		char sec[501];
		gets(sec);
		if (strcmp(sec, end) == 0) break;
		else {
			int len = strlen(sec);
			for (int i = len - 1; i >= 0; i--) printf("%c", sec[i]);
			printf("\n");
		}
	}
    return 0;
}

