#include<stdio.h>
#pragma warning (disable : 4996)

int k, S[14];

void rotto(int p, int su, int *ca);

int main()
{
	while (1) {
		scanf("%d", &k);
		if (k == 0) break;
		else {
			for (int i = 0; i < k; i++) scanf("%d", &S[i]);

			int cam[14];
			for (int i = 0; i < k; i++) cam[i] = 0;
			rotto(0, 0, cam);
		}
		printf("\n");
	}
	return 0;
}

void rotto(int p, int su, int *ca)
{
	for (int i = p; i < k; i++) {
		int cae[14];
		for (int j = 0; j < su; j++) cae[j] = ca[j];
		cae[su] = S[i];
		if (su == 5) {
			for (int j = 0; j <= su; j++) printf("%d ", cae[j]);
			printf("\n");
		}
		else if ((k - i) + su >= 6) rotto(i + 1, su + 1, cae);
	}
}
