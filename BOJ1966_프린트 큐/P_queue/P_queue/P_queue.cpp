#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		int N, M, queue[102], position[102], like[10], most = 0, print = 0;
		scanf("%d %d", &N, &M);

		for (int i = 1; i < 10; i++) like[i] = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &queue[i]);
			position[i] = i;
			like[queue[i]]++;
			if (most < queue[i]) most = queue[i];
		}

		while (1) {
			if (queue[0] == most) {
				print++;
				if (M == position[0]) {
					printf("%d\n", print);
					break;
				}
				like[queue[0]]--;
				if (like[queue[0]] == 0) {
					for (int i = queue[0] - 1; i > 0; i--) {
						if (like[i] > 0) {
							most = i; i = 0;
						}
					}
				}
				for (int i = 0; i < N - 1; i++) {
					queue[i] = queue[i + 1];
					position[i] = position[i + 1];
				}
				N--;
			}
			else {
				int temp1 = queue[0], temp2 = position[0];

				for (int i = 0; i < N - 1; i++) {
					queue[i] = queue[i + 1];
					position[i] = position[i + 1];
				}
				queue[N - 1] = temp1;
				position[N - 1] = temp2;
			}
		}
	}
    return 0;
}