#include<stdio.h>
#pragma warning(disable : 4996)

int N, card[500001];
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) card[i] = i;

	while (N > 1) {
		if (N % 2 == 0) {
			for (int i = 1; i <= N / 2; i++) {
				card[i] = card[i * 2];
			}
		}
		else {
			int temp = card[2];

			if (N / 2 == 1) {
				printf("%d\n", card[2]);
				return 0;
			}
			else {
				for (int i = 1; i <= (N / 2) - 1; i++) {
					card[i] = card[(i + 1) * 2];
				}
				card[N / 2] = temp;
			}
		}
		N = N / 2;
	}
	printf("%d\n", card[1]);

	return 0;
}