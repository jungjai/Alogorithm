#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char num[10];
	scanf("%s", num);

	int len, su;
	len = strlen(num);

	su = atoi(num);
	for (int i = su; i >= 4; i--) {
		int check = 0;
		itoa(i, num, 10);
		len = strlen(num);
		for (int j = 0; j < len; j++) {
			if (num[j] == '4' || num[j] == '7') continue;
			else {
				check = 1; j = len;
			}
		}
		if (check == 0) {
			printf("%s\n", num);
			return 0;
		}
	}
    return 0;
}

