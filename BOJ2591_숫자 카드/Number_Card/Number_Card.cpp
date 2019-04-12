#include<stdio.h>
#include<string.h>

#pragma warning(disable : 4996)

int len = 0, method = 1, check =0;
char num[41];

void card_check(int cip);

int main()
{
	freopen("input.txt", "r", stdin);

	int i;

	scanf("%s", num);

	len = strlen(num);

	for (i = 0; i < len; i++)
		num[i] = num[i] - '0';

	card_check(0);

	if (check == 1) method = 0;
	printf("%d\n", method);
}

void card_check(int cip)
{
	if (num[cip] != 0) {
		int i;
		for (i = cip; i < len - 1; i++) {
			if (num[i] != 0 && num[i + 1] != 0) {
				if (num[i] <= 2) {
					method++;
					card_check(i + 2);
				}
				else if (num[i] == 3 && num[i + 1] <= 4) {
					method++;
					card_check(i + 2);
				}					
			}
			else if (num[i] >= 4) check = 1;
		}
	}
	else if(cip<len) method--;
}