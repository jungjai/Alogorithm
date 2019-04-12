#include<stdio.h>

#pragma warning (disable : 4996)

int su;

int stri[100], ball[100];
char base[101][4];

int Correct(int a, int b, int c);

int main()
{
	freopen("input.txt", "r", stdin);

	int answer = 0;

	scanf("%d", &su);

	
	for (int i = 0; i < su; i++)
		scanf("%s %d %d", base[i], &stri[i], &ball[i]);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i != j) {
				for (int k = 1; k <= 9; k++) {
					if(i != k && j != k) {
						answer = answer + Correct(i+'0', j+'0', k+'0');
					}
				}
			}
		}
	}

	printf("%d\n", answer);
}

int Correct(int a, int b, int c)
{
	int chst, chba;

	for (int i = 0; i < su; i++) {
		chst = 0; chba = 0;

		if (base[i][0] == a) chst++;
		else if (base[i][0] == b || base[i][0] == c) chba++;

		if (base[i][1] == b) chst++;
		else if (base[i][1] == a || base[i][1] == c) chba++;

		if (base[i][2] == c) chst++;
		else if (base[i][2] == a || base[i][2] == b) chba++;

		if (chst != stri[i] || chba != ball[i]) return 0;
	}

	return 1;
}