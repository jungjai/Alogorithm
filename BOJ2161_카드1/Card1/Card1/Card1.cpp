#include<stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int N, card[1001];
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) card[i] = i;

	while (N > 1) {
		printf("%d ", card[1]);

		int temp = card[2];
		for (int i = 3; i <= N; i++) {
			card[i - 2] = card[i];
		}
		card[N - 1] = temp;
		N--;
	}
	printf("%d\n", card[1]);

    return 0;
}

