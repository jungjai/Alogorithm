#include<stdio.h>

int solution(int [], int);
int main()
{
	int N, A[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	printf("%d", solution(A, N));

    return 0;
}

int solution(int A[], int N) {
	int dice_p[7] = { 0, 6, 5, 4, 3, 2, 1 };
	int min;
	for (int i = 0; i < N; i++) {
		int check = 0;
		for (int j = 0; j < N; j++) {
			if (i != j && A[i] != A[j]) {
				if (A[i] == dice_p[A[j]]) check += 2;
				else check++;
			}
		}
		if (i == 0 || min > check) min = check;
	}
	return min;
}