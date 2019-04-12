#include<stdio.h>
#include<string.h>

#pragma warning (disable : 4996)

int change_su(char n[]);
void change_rome(int num);

int rome[7][2] = 
	{ { 'M', 1000 },{ 'D', 500 },{ 'C', 100 },{ 'L', 50 },{ 'X', 10 },{ 'V', 5 },{ 'I', 1 } };
//int rome[7] = { 1000, 500, 100, 50, 10, 5, 1 };

int main()
{
	freopen("input.txt", "r", stdin);
	
	
	int p, q;

	char su1[50], su2[50];

	scanf("%s", su1);
	scanf("%s", su2);

	p = change_su(su1);
	q = change_su(su2);

	printf("%d\n", p+q);
	change_rome(p+q);
}

int change_su(char n[])
{
	int op = 0, len;
	int i, j;

	len = strlen(n);

	for (i = 0; i < len; i++) {
		for (j = 0; j < 7; j++) {
			if (n[i] == rome[j][0]) {
				n[i] = j;

				j = 7;
			}
		}
	}

	for (i = 0; i < len; i++) {

		if (n[i] <= n[i + 1] || i == len - 1)
			op += rome[n[i]][1];
		else {
			op -= rome[n[i]][1];
			op += rome[n[i+1]][1];
			i++;
		}
	}

	return op;
}

void change_rome(int num)
{
	int i;

	int p;


	while (num != 0)
	{
		for (i = 0; i < 7; i++) {
			if ((i % 2 == 0) && num >= rome[i][1]) {
				printf("%c", rome[i][0]);
				num -= rome[i][1];
				i = 7;
			}

			else if ((i % 2 == 1)) {
				p = num / (rome[i + 1][1]);
				if (num >= rome[i][1]) {
					if (p == 9) {
						printf("%c%c", rome[i + 1][0], rome[i - 1][0]);
						num -= rome[i + 1][1] * 9;
						i = 7;
					}
					else {
						printf("%c", rome[i][0]);
						num -= rome[i][1];
						i = 7;
					}
				}
				else if (p == 4) {
					printf("%c%c", rome[i+1][0], rome[i][0]);
					num -= rome[i+1][1] * 4;
					i = 7;
				}
			}
			
		}
		if (num == 0) break;
	}
	printf("\n");
}