#include<stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc<T; tc++) {
		int N;
		char card[1001];
		char result[1001];
		scanf("%d\n", &N);
		for (int i = 0; i<N; i++) {
			scanf("%c ", &card[i]);
		}
		result[0] = card[0];
		for (int i = 1; i<N; i++) {
			if (result[0] <= card[i]) {
				for (int j = i; j >= 1; j--) result[j] = result[j - 1];
				result[0] = card[i];
			}
			else result[i] = card[i];
		}
		printf("#%d ", tc + 1);
		for (int i = 0; i<N; i++) printf("%c", result[i]);
		printf("\n");
		for (int i = 0; i<N; i++) { card[i] = 0; result[i] = 0; }
	}
	return 0;
}
