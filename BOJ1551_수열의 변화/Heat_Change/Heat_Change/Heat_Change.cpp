#include<stdio.h>

int N, K;

int main()
{
	int A[21];
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d,", &A[i]);

	for (int i = 1; i <= K; i++) {
		int B[21];
		for (int j = 1; j < N; j++) {
			B[j - 1] = A[j] - A[j - 1];
		}
		for (int j = 0; j < N - 1; j++) {
			A[j] = B[j];
		}
		N--;
	}
	for (int i = 0; i < N - 1; i++) {
		printf("%d,", A[i]);
	}
	printf("%d\n", A[N - 1]);
    return 0;
}

