#include<stdio.h>

int main()
{
	int M, su[3] = { 1, 2, 3 };
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int X, Y;
		scanf("%d %d", &X, &Y);
		
		int temp;
		temp = su[X - 1];
		su[X - 1] = su[Y - 1];
		su[Y - 1] = temp;
	}
	for (int i = 0; i < 3; i++) {
		if (su[i] == 1) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
    return 0;
}