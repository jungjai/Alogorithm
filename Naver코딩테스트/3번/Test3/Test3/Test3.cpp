#include<stdio.h>

int solution(int[], int);
int main()
{
	int N, A[3000001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	printf("%d", solution(A, N));

	return 0;
}

int solution(int A[], int N) {
	int max_last, max_cur;
	int result = 0;
	max_last = A[0]; max_cur = A[0];
	for (int i = 0; i < N; i++) {
		if (A[i] <= max_last) {
			max_last = max_cur;
			result = i + 1;
		}
		else if (A[i] > max_cur) max_cur = A[i];
	}

	return result;
}