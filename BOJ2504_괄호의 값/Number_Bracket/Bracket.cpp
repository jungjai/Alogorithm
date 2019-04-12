#include<stdio.h>
#include<string.h>

#pragma warning (disable : 4996)

char brac[31];
int len;

char chst[50];
int chp=0;
int check[50];

int Bracket();

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%s", brac);

	len = strlen(brac);

	if (brac[0] == ')' || brac[0] == ']' || len == 1) {
		printf("0\n");
		return 0;
	}
	else printf("%d\n", Bracket());

	return 0;
}

int Bracket()
{
	int chsum = 0;

	for (int i = 0; i < len; i++) {
		if (brac[i] == '(' || brac[i] == '[') {
			chst[chp] = brac[i];
			chp++;
		}

		else if (brac[i] == ')') {
			if (chst[chp - 1] == '(') {
				chst[chp - 1] = 2;
				check[chp - 1] = 2;
			}
			else if (chst[chp - 1] == '[') return 0;
			else if (check[chp - 1] >= 1) {
				chsum = 0;
				while (check[chp - 1] >= 1 && chp>=1) {
					chsum += check[chp - 1];
					check[chp - 1] = 0;
					
					chp--;
				}

				if (chst[chp - 1] == '[' || chp == 0) return 0;
				else if (chst[chp - 1] == '(') {
					chst[chp - 1] = chsum * 2;
					check[chp - 1] = chsum * 2;
				}
			}
		}

		else if (brac[i] == ']') {
			if (chst[chp - 1] == '[') {
				chst[chp - 1] = 3;
				check[chp - 1] = 3;
			}
			else if (chst[chp - 1] == '(') return 0;	
			else if (check[chp - 1] >= 1) {
				chsum = 0;
				while (check[chp - 1] >= 1 && chp >= 1) {
					chsum += check[chp - 1];
					check[chp - 1] = 0;

					chp--;
				}

				if (chst[chp - 1] == '(' || chp == 0) return 0;
				else if (chst[chp - 1] == '[') {
					chst[chp - 1] = chsum * 3;
					check[chp - 1] = chsum * 3;
				}
			}
		}
	}
	chp--;
	chsum = 0;
	while (chp >= 0) {
		if (check[chp] >= 1) {
			chsum += check[chp];
			chp--;
		}
		else if (chst[chp] == '(' || chst[chp] == ')' || chst[chp] == '[' || chst[chp] == ']') return 0;
	}

	return chsum;
}