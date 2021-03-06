#include<stdio.h>
#pragma warning (disable : 4996)

int N, talk[17][2];
int result = 0;

void profit(int, int);
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) scanf("%d %d", &talk[i][0], &talk[i][1]);
	
	for (int i = 1; i <= talk[1][0]; i++) {
		if (talk[i][0] + i - 1 <= N) {
			if (result < talk[i][1]) result = talk[i][1];
			profit(talk[i][0] + i, talk[i][1]);
		}
	}

	printf("%d", result);
    return 0;
}

void profit(int day, int pro)
{
	if ((day + talk[day][0] - 1) <= N) {
		for (int i = day; i <= (day + talk[day][0] - 1); i++) {
			if (talk[i][0] + i - 1 <= N) {
				if (result < pro + talk[i][1]) result = pro + talk[i][1];
				profit(talk[i][0] + i, pro + talk[i][1]);
			}
		}
	}
	else {
		for (int i = day; i <=	N; i++) {
			if (talk[i][0] + i - 1 <= N) {
				if (result < pro + talk[i][1]) result = pro + talk[i][1];
				profit(talk[i][0] + i, pro + talk[i][1]);
			}
		}
	}
}
