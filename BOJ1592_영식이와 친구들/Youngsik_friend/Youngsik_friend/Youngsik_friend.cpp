#include<stdio.h>

int N, M, L;
int P[1005];

int main()
{
	scanf("%d %d %d", &N, &M, &L);
	
	int position = 0, ball = 0;
	while (1) {
		ball++;
		P[position]++;
		if (P[position] == M) {
			printf("%d", ball - 1); return 0;
		}

		else {
			if (P[position] % 2 == 1) {
				position = ((position + L) % N);
			}
			else {
				if (position - L >= 0) position = position - L;
				else position = position - L + N;
			}
		}
	}
    return 0;
}

