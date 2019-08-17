#include<stdio.h>

int num;
char pic[51][6][8];
int result[3];
void compare(int, int);

int main()
{
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for(int j=0;j<5;j++) scanf("%s", pic[i][j]);
	}

	result[0] = 36; // max

	for (int i = 0; i < (num - 1); i++) {
		for (int j = i + 1; j < num; j++) {
			compare(i, j);
		}
	}

	printf("%d %d", result[1], result[2]);
}

void compare(int p, int q)
{
	int check = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (pic[p][i][j] != pic[q][i][j]) check++;
		}
	}
	if (check < result[0]) {
		result[0] = check;
		result[1] = p + 1;
		result[2] = q + 1;
	}
}