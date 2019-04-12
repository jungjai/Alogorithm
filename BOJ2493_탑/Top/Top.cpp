#include<stdio.h>

#pragma warning (disable : 4996)
int top[500000];
int sta[500000][2];
int main()
{
	freopen("input.txt", "r", stdin);
	
	int su;

	int check = 1;

	scanf("%d", &su);

	if (su == 1) {
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < su; i++) scanf("%d", &top[i]);

	sta[0][0] = top[su - 1];
	sta[0][1] = su - 1;

	for (int i = su - 2; i >= 0; i--) {
		if (sta[check - 1][0] < top[i]) {
			while (check >= 1 && sta[check - 1][0] < top[i]) {
				check--;
				top[sta[check][1]] = i + 1;
			}
		}

		sta[check][0] = top[i];
		sta[check][1] = i;
		check++;
	}
	while (check >= 0) {
		check--;
		top[sta[check][1]] = 0;
	}

	for (int i = 0; i < su-1; i++) printf("%d ", top[i]);

	printf("%d\n", top[su-1]);
	return 0;
}