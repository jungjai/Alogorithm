#include<stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		int color[51], car[1001], check1 = 0;
		int lob = 0;
		scanf("%d %d", &N, &M);
		for (int i = 0; i<M; i++) {
			scanf("%d", &color[i]);
			lob += color[i];
		}
		for (int i = 0; i<N; i++) scanf("%d", &car[i]);

		if (lob == 0 || lob >N) printf("#%d 0\n", tc);
		else {
			for (int i = lob; i <= N; i++) {
				int color_copy[51], check2 = 0;
				for (int j = 0; j<M; j++) color_copy[j] = color[j];

				for (int j = i - lob; j<i; j++) color_copy[car[j] - 1]--;
				for (int j = 0; j<M; j++) {
					if (color_copy[j] != 0) {
						check2 = 1;
						break;
					}
				}
				if (check2 == 0) {
					printf("#%d %d\n", tc, i - lob + 1);
					check1 = 1;
					break;
				}
			}

			if (check1 == 0) printf("#%d 0\n", tc);
		}
	}
	return 0;
}
