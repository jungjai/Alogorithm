#include<stdio.h>
#pragma warning <disable : 4996>

int N;
int A[1000001];
int main()
{
	int B, C;
	long long result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		result++;
		if (A[i] > 0) {
			if (A[i] % C == 0) result = result + ( A[i] / C );
			else result = result + ((A[i] / C) + 1);
		}
	}
	printf("%lld", result);
    return 0;
}

