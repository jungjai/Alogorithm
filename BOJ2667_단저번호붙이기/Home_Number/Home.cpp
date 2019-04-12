#include<stdio.h>

#pragma warning(disable : 4996)

int num;
char home[26][26];
int check = 0, hch[10000];

void Homecheck(int p, int q);

int main()
{
	int i, j, temp;

	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	if (num >= 5 && num <= 25) {
		for (i = 0; i < num; i++)
			scanf("%s", &home[i]);

		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {

				if (home[i][j] == '1') {
					check++;
					hch[check] = 1;
					Homecheck(i, j);
				}
			}
		}
		
		for (i = 1; i <= check;i++) {
			for (j = i + 1; j <= check; j++) {
				if (hch[i] > hch[j]) {
					temp = hch[i];
					hch[i] = hch[j];
					hch[j] = temp;
				}
			}
		}
		printf("%d\n", check);
		for (i = 1; i <= check; i++) {
			printf("%d\n", hch[i]);
		}
	}

	return 0;
}

void Homecheck(int p, int q)
{
	home[p][q] = '0';
	if (q+1<num && home[p][q + 1] == '1')
	{
		hch[check] ++;
		Homecheck(p, q + 1);
	}
	if (q-1>=0 && home[p][q - 1] == '1')
	{
		hch[check] ++;
		Homecheck(p, q - 1);
	}
	if (p+1<num && home[p + 1][q] == '1')
	{
		hch[check] ++;
		Homecheck(p + 1, q);
	}
	if (p-1>=0 && home[p - 1][q] == '1')
	{
		hch[check] ++;
		Homecheck(p -1, q);
	}
}