#include<stdio.h>

int N, K;
int coin[11];
int min = 0;

int main()
{	
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &coin[i]);
	
	for (int i = N - 1; i >= 0; i--) {
		min += (K / coin[i]);
		K -= (K / coin[i]) * coin[i];
		if (K == 0) i = -1;
	}
	printf("%d", min);
	return 0;
}